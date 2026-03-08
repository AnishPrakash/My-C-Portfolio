void moveZeroes(int* nums, int numsSize){
    for (int i = 0; i<numsSize; i++){
        int j = i+1;
        while(nums[i]==0 && j!=numsSize){
            int temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;
            j++;
        }
    }
}