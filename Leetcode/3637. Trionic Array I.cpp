bool isTrionic(int* nums, int numsSize) {
    if (numsSize < 3) return false;
    int i = 0;
    while (i + 1 < numsSize && nums[i] < nums[i + 1]) {
        i++;
    }
    if (i == 0 || i == numsSize - 1) return false;
    int p = i;
    while (i + 1 < numsSize && nums[i] > nums[i + 1]) {
        i++;
    }
    if (i == p || i == numsSize - 1) return false;
    int q = i;
    while (i + 1 < numsSize && nums[i] < nums[i + 1]) {
        i++;
    }
    return (i == numsSize - 1 && i > q);
}