int centeredSubarrays(int* nums, int numsSize) {
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        long long current_sum = 0;
        for (int j = i; j < numsSize; j++) {
            current_sum += nums[j];
            int found = 0;
            for (int k = i; k <= j; k++) {
                if (nums[k] == current_sum) {
                    found = 1;
                    break;
                }
            }
            if (found) {
                count++;
            }
        }
    }
    return count;
}