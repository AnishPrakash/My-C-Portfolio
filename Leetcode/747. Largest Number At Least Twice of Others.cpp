int dominantIndex(int* nums, int numsSize) {
    int maxIndex = -1;
    int maxVal = -1;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > maxVal) {
            maxVal = nums[i];
            maxIndex = i;
        }
    }
    for (int i = 0; i < numsSize; i++) {
        if (i != maxIndex && maxVal < 2 * nums[i]) {
            return -1;
        }
    }
    return maxIndex;
}
