int numOfWays(int n) {
    long long MOD = 1e9 + 7;
    long long aba = 6;
    long long abc = 6;
    
    for (int i = 2; i <= n; i++) {
        long long next_aba = (aba * 3 + abc * 2) % MOD;
        long long next_abc = (aba * 2 + abc * 2) % MOD;
        aba = next_aba;
        abc = next_abc;
    }
    return (int)((aba + abc) % MOD);
}