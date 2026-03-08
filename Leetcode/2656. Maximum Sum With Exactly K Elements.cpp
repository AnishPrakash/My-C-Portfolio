int maximizeSum(int* nums, int numsSize, int k) {
    int maxVal = nums[0];
    for(int i = 1; i < numsSize; i++)
        if(nums[i] > maxVal) maxVal = nums[i];

    return k * maxVal + (k * (k - 1)) / 2;
}
