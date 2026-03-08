bool* prefixesDivBy5(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    bool* result = (bool*)malloc(numsSize * sizeof(bool));
    int currentNum = 0;
    for (int i = 0; i < numsSize; i++) {
        currentNum = (currentNum * 2 + nums[i]) % 5;
        result[i] = (currentNum == 0);
    }
    return result;
}