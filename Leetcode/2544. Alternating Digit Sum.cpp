int alternateDigitSum(int n) {
    int sum = 0;
    int sign = 1;
    int temp = n;
    int digitCount = 0;
    while (temp > 0) {
        temp /= 10;
        digitCount++;
    }
    if (digitCount % 2 == 0) sign = -1;
    while (n > 0) {
        sum += (n % 10) * sign;
        sign *= -1;
        n /= 10;
    }

    return sum;
}