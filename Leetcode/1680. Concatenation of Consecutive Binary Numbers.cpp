int concatenatedBinary(int n) {
    long result = 0;
    int length = 0;
    int MOD = 1000000007;

    for (int i = 1; i <= n; i++) {
        if ((i & (i - 1)) == 0) {
            length++;
        }
        result = ((result << length) | i) % MOD;
    }

    return result;
}