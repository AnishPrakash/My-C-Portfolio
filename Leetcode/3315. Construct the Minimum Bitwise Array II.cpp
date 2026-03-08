int* minBitwiseArray(int* nums, int numsSize, int* returnSize) {
    int* ans = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        if (x == 2) {
            ans[i] = -1;
            continue;
        }
        for (int j = 1; j < 31; j++) {
            if (!((x >> j) & 1)){
                ans[i] = x ^ (1 << (j - 1));
                break;
            }
        }
    }
    return ans;
}