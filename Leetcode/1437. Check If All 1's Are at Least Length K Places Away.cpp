bool kLengthApart(int* nums, int numsSize, int k) {
    int lastPosition = -1;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            if (lastPosition != -1 && i - lastPosition - 1 < k) {
                return false;
            }
            lastPosition = i;
        }
    }
    return true;
}