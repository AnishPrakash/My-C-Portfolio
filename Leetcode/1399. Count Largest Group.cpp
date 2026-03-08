int getDigitSum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
int countLargestGroup(int n) {
    int counts[40] = {0};
    int maxFreq = 0;
    int result = 0;
    for (int i = 1; i <= n; i++) {
        int sum = getDigitSum(i);
        counts[sum]++;
        if (counts[sum] > maxFreq) {
            maxFreq = counts[sum];
        }
    }
    for (int j = 0; j < 40; j++) {
        if (counts[j] == maxFreq) {
            result++;
        }
    }
    return result;
}