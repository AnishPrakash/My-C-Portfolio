int minOperations(int* nums, int numsSize) {
    int ops = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] <= nums[i - 1]) {
            int diff = nums[i - 1] - nums[i] + 1;
            nums[i] += diff;
            ops += diff;
        }
    }
    return ops;
}