bool isSelfDividing(int n) {
    int temp = n;
    while (temp > 0) {
        int digit = temp % 10;
        if (digit == 0 || n % digit != 0) return false;
        temp /= 10;
    }
    return true;
}
int* selfDividingNumbers(int left, int right, int* returnSize) {
    int* res = (int*)malloc((right - left + 1) * sizeof(int));
    int count = 0;
    for (int i = left; i <= right; i++) {
        if (isSelfDividing(i)) res[count++] = i;
    }
    *returnSize = count;
    return res;
}