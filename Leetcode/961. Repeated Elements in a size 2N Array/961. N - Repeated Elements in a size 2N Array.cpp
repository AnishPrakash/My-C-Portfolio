int repeatedNTimes(int* nums, int numsSize) {
    int ans = 0, current_count = 1;
    for (int i = 0; i<numsSize; i++){
        for (int j = i+1; j<numsSize; j++){
            if (nums[i] == nums [j]){
                current_count++;
            }
        }
        if (current_count>1){
            ans = nums[i];
            break;
        }
    }
    return ans;
}