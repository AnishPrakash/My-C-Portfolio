int totalMoney(int n) {
    int weeks = n / 7;
    int remainingDays = n % 7;
    int total = (weeks * (28 + 28 + 7 * (weeks - 1))) / 2;
    for (int i = 0; i < remainingDays; i++) {
        total += (weeks + 1 + i);
    }
    return total;
}