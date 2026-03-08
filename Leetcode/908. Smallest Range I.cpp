int smallestRangeI(int* nums, int numsSize, int k) {
    int minVal = nums[0];
    int maxVal = nums[0];
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < minVal) minVal = nums[i];
        if (nums[i] > maxVal) maxVal = nums[i];
    }
    
    int diff = maxVal - minVal - 2 * k;
    return diff > 0 ? diff : 0;
}