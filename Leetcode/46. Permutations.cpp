#include <stdlib.h>
#include <string.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void backtrack(int* nums, int numsSize, int start, int*** res, int* returnSize, int** returnColumnSizes, int* capacity) {
    if (start == numsSize) {
        if (*returnSize == *capacity) {
            *capacity *= 2;
            *res = (int**)realloc(*res, *capacity * sizeof(int*));
            *returnColumnSizes = (int*)realloc(*returnColumnSizes, *capacity * sizeof(int));
        }
        (*res)[*returnSize] = (int*)malloc(numsSize * sizeof(int));
        memcpy((*res)[*returnSize], nums, numsSize * sizeof(int));
        (*returnColumnSizes)[*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }

    for (int i = start; i < numsSize; i++) {
        swap(&nums[start], &nums[i]);
        backtrack(nums, numsSize, start + 1, res, returnSize, returnColumnSizes, capacity);
        swap(&nums[start], &nums[i]);
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int capacity = 120;
    int** res = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));
    *returnSize = 0;

    backtrack(nums, numsSize, 0, &res, returnSize, returnColumnSizes, &capacity);
    return res;
}