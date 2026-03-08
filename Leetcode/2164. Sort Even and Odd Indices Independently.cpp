int cmpAsc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int cmpDesc(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int* sortEvenOdd(int* nums, int numsSize, int* returnSize) {
    int* evens = (int*)malloc((numsSize + 1) / 2 * sizeof(int));
    int* odds = (int*)malloc(numsSize / 2 * sizeof(int));
    int eCount = 0, oCount = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if (i % 2 == 0) evens[eCount++] = nums[i];
        else odds[oCount++] = nums[i];
    }
    
    qsort(evens, eCount, sizeof(int), cmpAsc);
    qsort(odds, oCount, sizeof(int), cmpDesc);
    
    int* result = (int*)malloc(numsSize * sizeof(int));
    int e = 0, o = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i % 2 == 0) result[i] = evens[e++];
        else result[i] = odds[o++];
    }
    
    free(evens);
    free(odds);
    *returnSize = numsSize;
    return result;
}