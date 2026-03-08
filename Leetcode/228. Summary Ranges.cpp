char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    char** result = (char**)malloc(numsSize * sizeof(char*));
    *returnSize = 0;
    
    for (int i = 0; i < numsSize; i++) {
        int start = nums[i];
        while (i + 1 < numsSize && nums[i] + 1 == nums[i + 1]) {
            i++;
        }
        
        result[*returnSize] = (char*)malloc(25 * sizeof(char));
        if (start == nums[i]) {
            sprintf(result[*returnSize], "%d", start);
        } else {
            sprintf(result[*returnSize], "%d->%d", start, nums[i]);
        }
        (*returnSize)++;
    }
    return result;
}