int* sortedSquares(int* nums, int numsSize, int* returnSize){
    int* result = (int*)malloc(numsSize * sizeof(int));
    int left = 0;
    int right = numsSize - 1;
    int index = numsSize - 1; 
    while (left <= right) {
        int leftVal = abs(nums[left]);
        int rightVal = abs(nums[right]);
        
        if (leftVal > rightVal) {
            result[index] = leftVal * leftVal;
            left++;
        } 
        else {
            result[index] = rightVal * rightVal;
            right--;
        }
        index--;
    }
    *returnSize = numsSize;
    return result;
}