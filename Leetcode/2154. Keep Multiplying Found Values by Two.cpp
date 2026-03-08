int findFinalValue(int* nums, int numsSize, int original) {
    bool found = true;
    while (found) {
        found = false;
        for (int i = 0; i < numsSize; i++) {
            if (nums[i] == original) {
                original *= 2;
                found = true;
                break;
            }
        }
    }
    return original;
}