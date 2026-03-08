#define MIN(a, b) ((a) < (b) ? (a) : (b))
int maxSideLength(int** mat, int matSize, int* matColSize, int threshold) {
    int m = matSize;
    int n = matColSize[0];
    int dp[301][301];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = mat[i-1][j-1] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }
    int maxLen = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int currentLen = maxLen + 1;
            if (i >= currentLen && j >= currentLen) {
                int r1 = i - currentLen + 1;
                int c1 = j - currentLen + 1;
                int squareSum = dp[i][j] - dp[r1-1][j] - dp[i][c1-1] + dp[r1-1][c1-1];
                if (squareSum <= threshold) {
                    maxLen++;
                }
            }
        }
    }
    return maxLen;
}