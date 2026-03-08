int* intersection(int** nums, int numsSize, int* numsColSize, int* returnSize) {
    int count[1001] = {0};
    
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsColSize[i]; j++) {
            count[nums[i][j]]++;
        }
    }
    
    int* result = (int*)malloc(1001 * sizeof(int));
    int k = 0;
    for (int i = 1; i <= 1000; i++) {
        if (count[i] == numsSize) {
            result[k++] = i;
        }
    }
    
    *returnSize = k;
    return result;
}