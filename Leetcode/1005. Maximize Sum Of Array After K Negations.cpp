int cmp1005(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int largestSumAfterKNegations(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), cmp1005);
    
    for (int i = 0; i < numsSize && k > 0; i++) {
        if (nums[i] < 0) {
            nums[i] = -nums[i];
            k--;
        }
    }
    
    if (k % 2 == 1) {
        int minIdx = 0;
        for (int i = 1; i < numsSize; i++) {
            if (nums[i] < nums[minIdx]) {
                minIdx = i;
            }
        }
        nums[minIdx] = -nums[minIdx];
    }
    
    int sum = 0;
    for (int i = 0; i < numsSize; i++) sum += nums[i];
    return sum;
}