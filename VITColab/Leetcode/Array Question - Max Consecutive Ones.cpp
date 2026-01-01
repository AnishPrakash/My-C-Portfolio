int findMaxConsecutiveOnes(int* nums, int numsSize){
    int ans = 0;
    int result = 0;
    for (int i = 0; i<numsSize; i++){
        if (nums[i] == 1){
            ans++;
            if (ans>result){
                result = ans;
            }
        }
        else{
            ans = 0;
        }
    }
    return result;
}