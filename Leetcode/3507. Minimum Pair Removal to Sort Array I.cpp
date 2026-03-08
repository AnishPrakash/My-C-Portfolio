bool isSorted(int* nums, int size) {
    for (int i = 0; i < size - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            return false;
        }
    }
    return true;
}
int minimumPairRemoval(int* nums, int numsSize) {
    int operations = 0;
    int currentSize = numsSize;
    while (!isSorted(nums, currentSize)) {
        int minSum = INT_MAX;
        int bestIndex = -1;
        for (int i = 0; i < currentSize - 1; i++) {
            int currentSum = nums[i] + nums[i + 1];
            if (currentSum < minSum) {
                minSum = currentSum;
                bestIndex = i;
            }
        }
        nums[bestIndex] = minSum;
        for (int i = bestIndex + 1; i < currentSize - 1; i++) {
            nums[i] = nums[i + 1];
        }
        currentSize--;
        operations++;
    }
    return operations;
}