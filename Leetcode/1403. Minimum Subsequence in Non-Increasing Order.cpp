int compare(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int* minSubsequence(int* nums, int numsSize, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    int totalSum = 0;
    for (int i = 0; i < numsSize; i++) totalSum += nums[i];

    int* res = (int*)malloc(sizeof(int) * numsSize);
    int currSum = 0;
    *returnSize = 0;

    for (int i = 0; i < numsSize; i++) {
        currSum += nums[i];
        res[(*returnSize)++] = nums[i];
        if (currSum > totalSum - currSum) break;
    }
    return res;
}