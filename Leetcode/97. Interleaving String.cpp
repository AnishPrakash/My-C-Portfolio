bool isInterleave(char* s1, char* s2, char* s3) {
    int n = strlen(s1), m = strlen(s2);
    if(n + m != strlen(s3)) return false;

    bool dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = true;

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(i > 0 && s1[i-1] == s3[i+j-1])
                dp[i][j] |= dp[i-1][j];
            if(j > 0 && s2[j-1] == s3[i+j-1])
                dp[i][j] |= dp[i][j-1];
        }
    }
    return dp[n][m];
}
