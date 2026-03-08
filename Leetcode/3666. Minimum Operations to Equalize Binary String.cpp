#include <stdlib.h>
#include <string.h>

int find(int* parent, int i) {
    int root = i;
    while (root != parent[root]) {
        root = parent[root];
    }
    int curr = i;
    while (curr != root) {
        int nxt = parent[curr];
        parent[curr] = root;
        curr = nxt;
    }
    return root;
}

int minOperations(char * s, int k) {
    int n = strlen(s);
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') c++;
    }
    
    if (c == 0) return 0;
    
    int* dsu[2];
    dsu[0] = (int*)malloc((n + 5) * sizeof(int));
    dsu[1] = (int*)malloc((n + 5) * sizeof(int));
    int* dist = (int*)malloc((n + 5) * sizeof(int));
    int* q = (int*)malloc((n + 5) * sizeof(int));
    
    for (int i = 0; i <= n + 2; i++) {
        dsu[0][i] = i;
        dsu[1][i] = i;
        dist[i] = -1;
    }
    
    int head = 0, tail = 0;
    
    dist[c] = 0;
    int p = c % 2;
    dsu[p][c] = find(dsu[p], c + 2);
    q[tail++] = c;
    
    while(head < tail) {
        int u = q[head++];
        
        int L = u - k;
        if (L < 0) L = -L;
        
        int R_inner = n - u - k;
        if (R_inner < 0) R_inner = -R_inner;
        int R = n - R_inner;
        
        int par = L % 2;
        int curr = find(dsu[par], L);
        
        while (curr <= R) {
            dist[curr] = dist[u] + 1;
            if (curr == 0) {
                int ans = dist[0];
                free(dsu[0]); free(dsu[1]); free(dist); free(q);
                return ans;
            }
            q[tail++] = curr;
            dsu[par][curr] = find(dsu[par], curr + 2);
            curr = find(dsu[par], curr);
        }
    }
    
    free(dsu[0]); free(dsu[1]); free(dist); free(q);
    return -1;
}