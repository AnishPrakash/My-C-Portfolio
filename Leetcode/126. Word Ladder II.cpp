#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

typedef struct {
    char** paths;
    int size;
} ResultPath;

int wordLen;
int listSize;
int* minLevel;
char*** results;
int returnSize;
int* returnColumnSizes;
int* adj[5005];
int adjSize[5005];
char** gWordList;
int gBeginIndex;
int gEndIndex;

bool oneCharDiff(char* a, char* b) {
    int diff = 0;
    for (int i = 0; i < wordLen; i++) {
        if (a[i] != b[i]) {
            diff++;
            if (diff > 1) return false;
        }
    }
    return diff == 1;
}

void dfs(int u, int* path, int pathLen) {
    path[pathLen] = u;
    if (u == gBeginIndex) {
        results[returnSize] = (char**)malloc((pathLen + 1) * sizeof(char*));
        for (int i = 0; i <= pathLen; i++) {
            results[returnSize][i] = strdup(gWordList[path[pathLen - i]]);
        }
        returnColumnSizes[returnSize] = pathLen + 1;
        returnSize++;
        return;
    }

    for (int i = 0; i < adjSize[u]; i++) {
        int v = adj[u][i];
        if (minLevel[v] == minLevel[u] - 1) {
            dfs(v, path, pathLen + 1);
        }
    }
}

char*** findLadders(char* beginWord, char* endWord, char** wordList, int wordListSize, int* returnSizeRef, int** returnColumnSizesRef) {
    wordLen = strlen(beginWord);
    listSize = wordListSize;
    gWordList = (char**)malloc((listSize + 1) * sizeof(char*));
    
    gBeginIndex = listSize;
    gEndIndex = -1;
    
    for(int i=0; i<listSize; i++) {
        gWordList[i] = wordList[i];
        if(strcmp(wordList[i], endWord) == 0) gEndIndex = i;
    }
    gWordList[listSize] = beginWord;

    if (gEndIndex == -1) {
        *returnSizeRef = 0;
        return NULL;
    }

    for (int i = 0; i <= listSize; i++) {
        adjSize[i] = 0;
        adj[i] = (int*)malloc((listSize + 1) * sizeof(int));
    }
    
    // Build Graph
    for (int i = 0; i <= listSize; i++) {
        for (int j = i + 1; j <= listSize; j++) {
            if (oneCharDiff(gWordList[i], gWordList[j])) {
                adj[i][adjSize[i]++] = j;
                adj[j][adjSize[j]++] = i;
            }
        }
    }

    // BFS
    minLevel = (int*)malloc((listSize + 1) * sizeof(int));
    for(int i=0; i<=listSize; i++) minLevel[i] = INT_MAX;
    
    int* queue = (int*)malloc((listSize + 1) * sizeof(int));
    int head = 0, tail = 0;
    
    queue[tail++] = gBeginIndex;
    minLevel[gBeginIndex] = 0;
    
    while(head < tail) {
        int u = queue[head++];
        if (u == gEndIndex) break; 
        
        for (int i = 0; i < adjSize[u]; i++) {
            int v = adj[u][i];
            if (minLevel[v] == INT_MAX) {
                minLevel[v] = minLevel[u] + 1;
                queue[tail++] = v;
            }
        }
    }
    
    results = (char***)malloc(20000 * sizeof(char**));
    returnColumnSizes = (int*)malloc(20000 * sizeof(int));
    returnSize = 0;

    if (minLevel[gEndIndex] != INT_MAX) {
        int* path = (int*)malloc((listSize + 1) * sizeof(int));
        dfs(gEndIndex, path, 0);
        free(path);
    }

    *returnSizeRef = returnSize;
    *returnColumnSizesRef = returnColumnSizes;

    // Cleanup (Partial for brevity)
    free(minLevel);
    free(queue);
    free(gWordList);
    for(int i=0; i<=listSize; i++) free(adj[i]);

    return results;
}