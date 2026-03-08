int* singleNumber(int* nums, int numsSize, int* returnSize) {
    long bitmask = 0;
    for (int i = 0; i < numsSize; i++) {
        bitmask ^= nums[i];
    }

    long diff = bitmask & (-bitmask);
    int x = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if ((nums[i] & diff) != 0) {
            x ^= nums[i];
        }
    }

    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = x;
    result[1] = bitmask ^ x;
    
    *returnSize = 2;
    return result;
}