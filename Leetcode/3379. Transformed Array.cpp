int* constructTransformedArray(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++) {
        int steps = nums[i];
        int targetIndex = ((i + steps) % numsSize + numsSize) % numsSize;
        result[i] = nums[targetIndex];
    }
    return result;
}