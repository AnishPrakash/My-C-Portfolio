#define INF LLONG_MAX
typedef struct Edge {
    int to;
    int weight;
    struct Edge* next;
} Edge;

typedef struct {
    int node;
    long long dist;
} HeapNode;

typedef struct {
    HeapNode* data;
    int size;
    int capacity;
} MinHeap;

// Min-Heap Functions
MinHeap* createHeap(int capacity) {
    MinHeap* h = (MinHeap*)malloc(sizeof(MinHeap));
    h->data = (HeapNode*)malloc(sizeof(HeapNode) * capacity);
    h->size = 0;
    h->capacity = capacity;
    return h;
}

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void push(MinHeap* h, int node, long long dist) {
    int i = h->size++;
    h->data[i] = (HeapNode){node, dist};
    while (i > 0 && h->data[i].dist < h->data[(i - 1) / 2].dist) {
        swap(&h->data[i], &h->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

HeapNode pop(MinHeap* h) {
    HeapNode top = h->data[0];
    h->data[0] = h->data[--h->size];
    int i = 0;
    while (i * 2 + 1 < h->size) {
        int small = i * 2 + 1;
        if (small + 1 < h->size && h->data[small + 1].dist < h->data[small].dist) small++;
        if (h->data[i].dist <= h->data[small].dist) break;
        swap(&h->data[i], &h->data[small]);
        i = small;
    }
    return top;
}

long long minCost(int n, int** edges, int edgesSize, int* edgesColSize) {
    Edge** adj = (Edge**)calloc(n, sizeof(Edge*));
    
    // Build the graph: Forward (w) and Backward (2w)
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0], v = edges[i][1], w = edges[i][2];
        
        // Forward edge
        Edge* e1 = (Edge*)malloc(sizeof(Edge));
        e1->to = v; e1->weight = w; e1->next = adj[u]; adj[u] = e1;
        
        // Reversed edge
        Edge* e2 = (Edge*)malloc(sizeof(Edge));
        e2->to = u; e2->weight = 2 * w; e2->next = adj[v]; adj[v] = e2;
    }

    long long* dist = (long long*)malloc(n * sizeof(long long));
    for (int i = 0; i < n; i++) dist[i] = INF;
    dist[0] = 0;

    MinHeap* pq = createHeap(edgesSize * 2 + n);
    push(pq, 0, 0);

    while (pq->size > 0) {
        HeapNode current = pop(pq);
        int u = current.node;
        long long d = current.dist;

        if (d > dist[u]) continue;
        if (u == n - 1) break;

        for (Edge* e = adj[u]; e != NULL; e = e->next) {
            if (dist[u] + e->weight < dist[e->to]) {
                dist[e->to] = dist[u] + e->weight;
                push(pq, e->to, dist[e->to]);
            }
        }
    }

    long long result = dist[n - 1];
    // Cleanup memory (adj list, heap, dist) omitted for brevity
    return (result == INF) ? -1 : result;
}