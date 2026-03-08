int minOperations(int* nums, int numsSize, int* target, int targetSize) {
    int operations = 0;
    bool used[100001] = {false}; 
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != target[i]) {
            int x = nums[i];
            if (!used[x]) {
                operations++;
                used[x] = true;
            }
        }
    }
    return operations;
}