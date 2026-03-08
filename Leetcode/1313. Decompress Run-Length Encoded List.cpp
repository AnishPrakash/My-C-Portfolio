int* decompressRLElist(int* nums, int numsSize, int* returnSize) {
    int len = 0;
    for (int i = 0; i < numsSize; i += 2) {
        len += nums[i];
    }
    
    *returnSize = len;
    int* result = (int*)malloc(len * sizeof(int));
    int index = 0;
    
    for (int i = 0; i < numsSize; i += 2) {
        int freq = nums[i];
        int val = nums[i + 1];
        for (int k = 0; k < freq; k++) {
            result[index++] = val;
        }
    }
    
    return result;
}