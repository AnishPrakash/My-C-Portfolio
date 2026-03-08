int scoreDifference(int* nums, int numsSize) {
    int score_diff = 0;
    int is_p1_active = 1;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] % 2 != 0) {
            is_p1_active = !is_p1_active;
        }
        if (i % 6 == 5) {
            is_p1_active = !is_p1_active;
        }
        if (is_p1_active) {
            score_diff += nums[i];
        } else {
            score_diff -= nums[i];
        }
    }
    return score_diff;
}