int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
int findLHS(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    int left = 0;
    int maxLen = 0;
    for (int right = 0; right < numsSize; right++) {
        while (nums[right] - nums[left] > 1) {
            left++;
        }
        if (nums[right] - nums[left] == 1) {
            int currentLen = right - left + 1;
            if (currentLen > maxLen) {
                maxLen = currentLen;
            }
        }
    }
    return maxLen;
}