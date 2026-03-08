int maxSum(int* nums, int numsSize) {
    bool seen[101] = {false};
    int sum = 0;
    int maxVal = nums[0];

    for(int i = 0; i < numsSize; i++) {
        if(nums[i] > maxVal) maxVal = nums[i];

        if(nums[i] > 0 && !seen[nums[i]]) {
            sum += nums[i];
            seen[nums[i]] = true;
        }
    }

    return (sum > 0) ? sum : maxVal;
}
