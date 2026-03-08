#include <stdlib.h>

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    int m = obstacleGridSize;
    int n = obstacleGridColSize[0];
    
    if (obstacleGrid[0][0] == 1) return 0;
    
    long long* dp = (long long*)calloc(n, sizeof(long long));
    dp[0] = 1;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[i][j] == 1) {
                dp[j] = 0;
            } else if (j > 0) {
                dp[j] += dp[j - 1];
            }
        }
    }
    
    int result = (int)dp[n - 1];
    free(dp);
    return result;
}