int countElements(int* nums, int numsSize) {
    int min = INT_MAX, max = INT_MIN;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < min) min = nums[i];
        if (nums[i] > max) max = nums[i];
    }
    
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > min && nums[i] < max) {
            count++;
        }
    }
    return count;
}