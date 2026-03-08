int minStartValue(int* nums, int numsSize) {
    int minPrefixSum = 0;
    int currentSum = 0;
    for (int i = 0; i < numsSize; i++) {
        currentSum += nums[i];
        if (currentSum < minPrefixSum) {
            minPrefixSum = currentSum;
        }
    }
    return 1 - minPrefixSum;
}