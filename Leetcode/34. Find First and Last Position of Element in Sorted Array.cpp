/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int* result = (int*)malloc(2*sizeof(int));
    *returnSize = 2;
    result[0] = -1;
    result[1] = -1;
    for (int i = 0; i<numsSize; i++){
        if (nums[i] == target){
            if(result[0]==-1){
                result[0] = i;
            }
            result[1] = i;
        }
    }
    return result;
}