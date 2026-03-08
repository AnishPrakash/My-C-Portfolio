int* minBitwiseArray(int* nums, int numsSize, int* returnSize) {
    int* ans = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    if (ans == NULL) {
        return NULL; 
    }
    for (int i = 0; i < numsSize; i++) {
        int val = nums[i];
        if (val == 2) {
            ans[i] = -1;
        } else {
            int next_val = val + 1;
            int lowbit_of_next = next_val & (-next_val);
            ans[i] = val - (lowbit_of_next >> 1);
        }
    }
    return ans;
}