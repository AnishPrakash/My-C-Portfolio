int majorityElement(int* nums, int numsSize) {
    int count = 1, majority = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == majority) {
            count++;
        } 
        else {
            count--;
        }
        if (count == 0) {
            majority = nums[i];
            count = 1;
        }
    }
    count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == majority) {
            count++;
        }
    }
    int result = (count > numsSize / 2) ? majority : -1;
    return result;
}