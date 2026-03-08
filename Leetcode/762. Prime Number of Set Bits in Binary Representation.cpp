int countBits(int x) {
    int c = 0;
    while (x) {
        c += x & 1;
        x >>= 1;
    }
    return c;
}

int countPrimeSetBits(int left, int right) {
    int primes[20] = {0};
    int p[] = {2,3,5,7,11,13,17,19};
    for (int i = 0; i < 8; i++) primes[p[i]] = 1;

    int ans = 0;
    for (int x = left; x <= right; x++) {
        if (primes[countBits(x)]) ans++;
    }
    return ans;
}
