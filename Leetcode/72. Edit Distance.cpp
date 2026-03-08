int min(int a, int b) { return a < b ? a : b; }
int minDistance(char* word1, char* word2) {
    int n = strlen(word1), m = strlen(word2);
    int** dp = (int**)malloc((n+1) * sizeof(int*));
    for (int i = 0; i <= n; i++)
        dp[i] = (int*)malloc((m+1) * sizeof(int));
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (word1[i-1] == word2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
        }
    }
    return dp[n][m];
}
