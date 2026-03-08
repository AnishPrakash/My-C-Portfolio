#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char** res;
int resSize;

bool canBreak(char* s, char** wordDict, int wordDictSize) {
    int n = strlen(s);
    bool* dp = (bool*)calloc(n + 1, sizeof(bool));
    dp[0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < wordDictSize; j++) {
            int len = strlen(wordDict[j]);
            if (i >= len && dp[i - len] && strncmp(s + i - len, wordDict[j], len) == 0) {
                dp[i] = true;
                break;
            }
        }
    }
    bool ret = dp[n];
    free(dp);
    return ret;
}

void dfs(char* s, int start, int n, char** wordDict, int wordDictSize, char* path, int pIdx) {
    if (start == n) {
        path[pIdx - 1] = '\0';
        res = (char**)realloc(res, (resSize + 1) * sizeof(char*));
        res[resSize] = strdup(path);
        resSize++;
        return;
    }
    
    for (int i = 0; i < wordDictSize; i++) {
        int wLen = strlen(wordDict[i]);
        if (start + wLen <= n && strncmp(s + start, wordDict[i], wLen) == 0) {
            strcpy(path + pIdx, wordDict[i]);
            path[pIdx + wLen] = ' ';
            dfs(s, start + wLen, n, wordDict, wordDictSize, path, pIdx + wLen + 1);
        }
    }
}

char** wordBreak(char* s, char** wordDict, int wordDictSize, int* returnSize) {
    resSize = 0;
    res = NULL;
    
    if (!canBreak(s, wordDict, wordDictSize)) {
        *returnSize = 0;
        return NULL;
    }
    
    int n = strlen(s);
    char* path = (char*)malloc((n * 20 + 100) * sizeof(char));
    
    dfs(s, 0, n, wordDict, wordDictSize, path, 0);
    
    free(path);
    *returnSize = resSize;
    return res;
}