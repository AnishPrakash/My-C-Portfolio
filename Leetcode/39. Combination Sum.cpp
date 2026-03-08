#include <stdlib.h>
#include <string.h>

void dfs(int* candidates, int candidatesSize, int target, int*** res, int* returnSize, int** returnColumnSizes, int* path, int pathLen, int start, int* capacity) {
    if (target < 0) return;
    if (target == 0) {
        if (*returnSize == *capacity) {
            *capacity *= 2;
            *res = (int**)realloc(*res, *capacity * sizeof(int*));
            *returnColumnSizes = (int*)realloc(*returnColumnSizes, *capacity * sizeof(int));
        }
        (*res)[*returnSize] = (int*)malloc(pathLen * sizeof(int));
        memcpy((*res)[*returnSize], path, pathLen * sizeof(int));
        (*returnColumnSizes)[*returnSize] = pathLen;
        (*returnSize)++;
        return;
    }
    
    for (int i = start; i < candidatesSize; i++) {
        path[pathLen] = candidates[i];
        dfs(candidates, candidatesSize, target - candidates[i], res, returnSize, returnColumnSizes, path, pathLen + 1, i, capacity);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int capacity = 1000;
    int** res = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));
    *returnSize = 0;
    
    int* path = (int*)malloc(500 * sizeof(int));
    
    dfs(candidates, candidatesSize, target, &res, returnSize, returnColumnSizes, path, 0, 0, &capacity);
    
    free(path);
    return res;
}