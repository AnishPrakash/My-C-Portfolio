int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize) {
    int* target = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    for (int i = 0; i < numsSize; i++) {
        int idx = index[i];
        for (int j = i; j > idx; j--) {
            target[j] = target[j - 1];
        }
        target[idx] = nums[i];
    }
    return target;
}