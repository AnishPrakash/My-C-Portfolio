#include <stdlib.h>
#include <string.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void backtrack(int* nums, int numsSize, int* path, int depth, int* visited, int*** res, int* returnSize, int** returnColumnSizes, int* capacity) {
    if (depth == numsSize) {
        if (*returnSize == *capacity) {
            *capacity *= 2;
            *res = (int**)realloc(*res, *capacity * sizeof(int*));
            *returnColumnSizes = (int*)realloc(*returnColumnSizes, *capacity * sizeof(int));
        }
        (*res)[*returnSize] = (int*)malloc(numsSize * sizeof(int));
        memcpy((*res)[*returnSize], path, numsSize * sizeof(int));
        (*returnColumnSizes)[*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }

    for (int i = 0; i < numsSize; i++) {
        if (visited[i] || (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])) {
            continue;
        }
        visited[i] = 1;
        path[depth] = nums[i];
        backtrack(nums, numsSize, path, depth + 1, visited, res, returnSize, returnColumnSizes, capacity);
        visited[i] = 0;
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);
    
    int capacity = 120;
    int** res = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));
    *returnSize = 0;
    
    int* path = (int*)malloc(numsSize * sizeof(int));
    int* visited = (int*)calloc(numsSize, sizeof(int));
    
    backtrack(nums, numsSize, path, 0, visited, &res, returnSize, returnColumnSizes, &capacity);
    
    free(path);
    free(visited);
    return res;
}