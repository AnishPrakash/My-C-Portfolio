int minimumPrefixLength(int* nums, int numsSize){
    if(numsSize<=1){
        return 0;
    }
    for (int i = numsSize-2; i>=0; i--){
        if(nums[i]>=nums[i+1]){
            return i+1;
        }
    }
    return 0;
}