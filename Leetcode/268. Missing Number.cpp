int missingNumber(int* nums, int numsSize) {
    int xorSum = numsSize;
    for (int i = 0; i < numsSize; i++) {
        xorSum ^= i ^ nums[i];
    }
    return xorSum;
}