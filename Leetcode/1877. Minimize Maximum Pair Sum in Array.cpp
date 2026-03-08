int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
int minPairSum(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);   
    int max_sum = 0;
    int left = 0;
    int right = numsSize - 1;
    while (left < right) {
        int current_sum = nums[left] + nums[right];
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
        left++;
        right--;
    }
    return max_sum;
}