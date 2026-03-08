int compare(const void *a, const void *b) {
    int int_a = *((int*)a);
    int int_b = *((int*)b);
    if (int_a < int_b) return -1;
    if (int_a > int_b) return 1;
    return 0;
}
int minRemoval(int* nums, int numsSize, int k) {
    if (numsSize == 0) return 0;
    qsort(nums, numsSize, sizeof(int), compare);
    int max_kept = 0;
    int left = 0;
    for (int right = 0; right < numsSize; right++) {
        while ((long long)nums[right] > (long long)nums[left] * k) {
            left++;
        }
        int current_len = right - left + 1;
        if (current_len > max_kept) {
            max_kept = current_len;
        }
    }
    return numsSize - max_kept;
}