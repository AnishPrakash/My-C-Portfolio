int findNumbers(int* nums, int numsSize) {
    int even = 0;
    for (int i = 0; i < numsSize; i++) {
        int temp = nums[i];
        int digits = 0;
        while (temp > 0) {
            temp /= 10;
            digits++;
        }
        if (digits % 2 == 0) {
            even++;
        }
    }
    return even;
}