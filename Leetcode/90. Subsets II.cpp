int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void backtrack(int* nums, int numsSize, int start, int* current, int currentSize, int*** result, int* returnSize, int** returnColumnSizes) {
    (*result)[*returnSize] = (int*)malloc(currentSize * sizeof(int));
    for (int i = 0; i < currentSize; i++) {
        (*result)[*returnSize][i] = current[i];
    }
    (*returnColumnSizes)[*returnSize] = currentSize;
    (*returnSize)++;

    for (int i = start; i < numsSize; i++) {
        if (i > start && nums[i] == nums[i - 1]) continue;
        current[currentSize] = nums[i];
        backtrack(nums, numsSize, i + 1, current, currentSize + 1, result, returnSize, returnColumnSizes);
    }
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);
    
    int maxSubsets = 1 << numsSize;
    int** result = (int**)malloc(maxSubsets * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxSubsets * sizeof(int));
    *returnSize = 0;
    int* current = (int*)malloc(numsSize * sizeof(int));

    backtrack(nums, numsSize, 0, current, 0, &result, returnSize, returnColumnSizes);

    free(current);
    return result;
}