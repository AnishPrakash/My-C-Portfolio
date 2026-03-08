#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define INF 1e14 
typedef struct TrieNode {
    struct TrieNode *children[26];
    int id;
} TrieNode;
TrieNode* createNode() {
    TrieNode *node = (TrieNode*)malloc(sizeof(TrieNode));
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    node->id = -1;
    return node;
}
int insert(TrieNode *root, char *str, int *count) {
    TrieNode *curr = root;
    for (int i = 0; str[i]; i++) {
        int idx = str[i] - 'a';
        if (!curr->children[idx]) {
            curr->children[idx] = createNode();
        }
        curr = curr->children[idx];
    }
    if (curr->id == -1) {
        curr->id = (*count)++;
    }
    return curr->id;
}
void freeTrie(TrieNode *root) {
    if (!root) return;
    for (int i = 0; i < 26; i++) {
        freeTrie(root->children[i]);
    }
    free(root);
}
long long minimumCost(char* source, char* target, char** original, int originalSize, char** changed, int changedSize, int* cost, int costSize) {
    int n = strlen(source);
    int uniqueCount = 0;
    TrieNode *root = createNode();
    for (int i = 0; i < originalSize; i++) {
        insert(root, original[i], &uniqueCount);
        insert(root, changed[i], &uniqueCount);
    }
    long long **dist = (long long**)malloc(uniqueCount * sizeof(long long*));
    for (int i = 0; i < uniqueCount; i++) {
        dist[i] = (long long*)malloc(uniqueCount * sizeof(long long));
        for (int j = 0; j < uniqueCount; j++) {
            dist[i][j] = (i == j) ? 0 : INF;
        }
    }
    for (int i = 0; i < originalSize; i++) {
        int u = insert(root, original[i], &uniqueCount);
        int v = insert(root, changed[i], &uniqueCount);
        dist[u][v] = MIN(dist[u][v], (long long)cost[i]);
    }
    for (int k = 0; k < uniqueCount; k++) {
        for (int i = 0; i < uniqueCount; i++) {
            if (dist[i][k] == INF) continue;
            for (int j = 0; j < uniqueCount; j++) {
                if (dist[k][j] < INF) {
                    dist[i][j] = MIN(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    long long *dp = (long long*)malloc((n + 1) * sizeof(long long));
    for(int i = 0; i <= n; i++) dp[i] = INF;
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (source[i] == target[i]) {
            dp[i] = dp[i + 1];
        }
        TrieNode *nodeS = root;
        TrieNode *nodeT = root;
        for (int len = 0; i + len < n; len++) {
            int charIdxS = source[i + len] - 'a';
            int charIdxT = target[i + len] - 'a';
            nodeS = nodeS->children[charIdxS];
            nodeT = nodeT->children[charIdxT];
            if (!nodeS || !nodeT) break;
            if (nodeS->id != -1 && nodeT->id != -1) {
                long long transformationCost = dist[nodeS->id][nodeT->id];
                if (transformationCost < INF && dp[i + len + 1] < INF) {
                    dp[i] = MIN(dp[i], transformationCost + dp[i + len + 1]);
                }
            }
        }
    }
    long long result = dp[0];
    freeTrie(root);
    for (int i = 0; i < uniqueCount; i++) free(dist[i]);
    free(dist);
    free(dp);
    return (result >= INF) ? -1 : result;
}