int nthSuperUglyNumber(int n, int* primes, int primesSize) {
    if (n == 1) return 1;
    long* dp = (long*)malloc(n * sizeof(long));
    int* indices = (int*)calloc(primesSize, sizeof(int));
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        long min_val = LONG_MAX;
        for (int j = 0; j < primesSize; j++) {
            long candidate = dp[indices[j]] * (long)primes[j];
            if (candidate < min_val) {
                min_val = candidate;
            }
        }
        dp[i] = min_val;
        for (int j = 0; j < primesSize; j++) {
            if (dp[indices[j]] * (long)primes[j] == min_val) {
                indices[j]++;
            }
        }
    }
    int result = (int)dp[n - 1];
    free(dp);
    free(indices);
    return result;
}