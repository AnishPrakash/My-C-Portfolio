int findNonMinOrMax(int* nums, int numsSize) {
    int min = 101, max = 0;
    for (int i = 0; i<numsSize; i++){
        if (nums[i]>max){
            max = nums[i];
        }
        if (nums[i]<min){
            min = nums[i];
        }
    }
    for (int i = 0; i<numsSize; i++){
        if (nums[i]!= max && nums[i]!=min){
            return nums[i];
        }
    }
    return -1;
}