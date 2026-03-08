int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
int minimumDifference(int* nums, int numsSize, int k) {
    if (k <= 1) return 0;
    qsort(nums, numsSize, sizeof(int), compare);
    int minDiff = nums[k - 1] - nums[0];
    for (int i = 1; i <= numsSize - k; i++) {
        int currentDiff = nums[i + k - 1] - nums[i];
        if (currentDiff < minDiff) {
            minDiff = currentDiff;
        }
    }
    return minDiff;
}