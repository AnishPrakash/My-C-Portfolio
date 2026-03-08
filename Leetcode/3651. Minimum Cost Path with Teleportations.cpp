#include <stdio.h>
#include <stdlib.h>

typedef long long ll;
#define INF 1000000000000000000LL

typedef struct {
    int r, c, v;
} Cell;

typedef struct {
    ll d;
    int t, id;
} Node;

// ---------- Min Heap ----------
typedef struct {
    Node *a;
    int sz;
} Heap;

static inline void heap_push(Heap *h, Node x) {
    int i = ++h->sz;
    while (i > 1 && h->a[i/2].d > x.d) {
        h->a[i] = h->a[i/2];
        i /= 2;
    }
    h->a[i] = x;
}

static inline Node heap_pop(Heap *h) {
    Node ret = h->a[1];
    Node last = h->a[h->sz--];
    int i = 1;
    while (i * 2 <= h->sz) {
        int c = i * 2;
        if (c + 1 <= h->sz && h->a[c+1].d < h->a[c].d) c++;
        if (h->a[c].d >= last.d) break;
        h->a[i] = h->a[c];
        i = c;
    }
    h->a[i] = last;
    return ret;
}

static inline int heap_empty(Heap *h) {
    return h->sz == 0;
}

// ---------- Sort cells by value ----------
int cmpCell(const void *a, const void *b) {
    return ((Cell*)a)->v - ((Cell*)b)->v;
}

// ---------- Main ----------
int minCost(int** grid, int m, int* gridColSize, int k) {
    int n = gridColSize[0];
    int total = m * n;

    // Flatten grid index
    #define ID(i,j) ((i)*n + (j))

    // Collect cells
    Cell *cells = (Cell*)malloc(total * sizeof(Cell));
    int idx = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cells[idx++] = (Cell){i, j, grid[i][j]};
    qsort(cells, total, sizeof(Cell), cmpCell);

    // dist[t][id]
    ll *dist = (ll*)malloc((ll)(k+1) * total * sizeof(ll));
    for (ll i = 0; i < (ll)(k+1) * total; i++) dist[i] = INF;
    dist[0] = 0;

    // teleport pointer per layer
    int *ptr = (int*)calloc(k+1, sizeof(int));

    // heap size upper bound ≈ states * log(states)
    int maxStates = (k+1) * total;
    Heap h;
    h.sz = 0;
    h.a = (Node*)malloc((maxStates + 5) * sizeof(Node));

    heap_push(&h, (Node){0, 0, 0});

    while (!heap_empty(&h)) {
        Node cur = heap_pop(&h);
        ll d = cur.d;
        int t = cur.t;
        int id = cur.id;

        if (d != dist[(ll)t * total + id]) continue;

        int i = id / n;
        int j = id % n;

        // ---- Normal moves ----
        if (i + 1 < m) {
            int nid = ID(i+1, j);
            ll nd = d + grid[i+1][j];
            ll *ref = &dist[(ll)t * total + nid];
            if (nd < *ref) {
                *ref = nd;
                heap_push(&h, (Node){nd, t, nid});
            }
        }
        if (j + 1 < n) {
            int nid = ID(i, j+1);
            ll nd = d + grid[i][j+1];
            ll *ref = &dist[(ll)t * total + nid];
            if (nd < *ref) {
                *ref = nd;
                heap_push(&h, (Node){nd, t, nid});
            }
        }

        // ---- Teleport moves ----
        if (t < k) {
            int *p = &ptr[t];
            while (*p < total && cells[*p].v <= grid[i][j]) {
                int r = cells[*p].r;
                int c = cells[*p].c;
                int nid = ID(r,c);
                ll *ref = &dist[(ll)(t+1) * total + nid];
                if (d < *ref) {
                    *ref = d;
                    heap_push(&h, (Node){d, t+1, nid});
                }
                (*p)++;
            }
        }
    }

    ll ans = INF;
    int target = ID(m-1, n-1);
    for (int t = 0; t <= k; t++) {
        ll v = dist[(ll)t * total + target];
        if (v < ans) ans = v;
    }

    free(cells);
    free(dist);
    free(ptr);
    free(h.a);

    return (int)ans;
}
