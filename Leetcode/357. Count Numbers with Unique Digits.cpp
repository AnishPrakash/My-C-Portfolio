int countNumbersWithUniqueDigits(int n) {
    if (n == 0) return 1;
    int totalCount = 10;
    int currentUnique = 9;
    int availableNumbers = 9;
    for (int i = 2; i <= n && i <= 10; i++) {
        currentUnique = currentUnique * availableNumbers;
        totalCount += currentUnique;
        availableNumbers--;
    }
    return totalCount;
}