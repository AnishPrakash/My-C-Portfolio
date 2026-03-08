#define MIN(a, b) ((a) < (b) ? (a) : (b))
int largestMagicSquare(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    int** rowSum = (int**)malloc(m * sizeof(int*));
    int** colSum = (int**)malloc((m + 1) * sizeof(int*)); 
    for (int i = 0; i < m; i++) {
        rowSum[i] = (int*)malloc((n + 1) * sizeof(int));
        rowSum[i][0] = 0;
        for (int j = 0; j < n; j++) {
            rowSum[i][j + 1] = rowSum[i][j] + grid[i][j];
        }
    }
    for (int i = 0; i <= m; i++) {
        colSum[i] = (int*)malloc(n * sizeof(int));
    }
    for (int j = 0; j < n; j++) colSum[0][j] = 0;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            colSum[i + 1][j] = colSum[i][j] + grid[i][j];
        }
    }
    for (int k = MIN(m, n); k > 1; k--) {
        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                int target = rowSum[i][j + k] - rowSum[i][j];
                int isMagic = 1;
                for (int r = i + 1; r < i + k; r++) {
                    int current_row_sum = rowSum[r][j + k] - rowSum[r][j];
                    if (current_row_sum != target) {
                        isMagic = 0;
                        break;
                    }
                }
                if (!isMagic) continue;
                for (int c = j; c < j + k; c++) {
                    int current_col_sum = colSum[i + k][c] - colSum[i][c];
                    if (current_col_sum != target) {
                        isMagic = 0;
                        break;
                    }
                }
                if (!isMagic) continue;
                int d1 = 0;
                for (int x = 0; x < k; x++) {
                    d1 += grid[i + x][j + x];
                }
                if (d1 != target) continue;
                int d2 = 0;
                for (int x = 0; x < k; x++) {
                    d2 += grid[i + x][j + k - 1 - x];
                }
                if (d2 != target) continue;
                for (int x = 0; x < m; x++) free(rowSum[x]);
                for (int x = 0; x <= m; x++) free(colSum[x]);
                free(rowSum);
                free(colSum);
                return k; 
            }
        }
    }
    for (int x = 0; x < m; x++) free(rowSum[x]);
    for (int x = 0; x <= m; x++) free(colSum[x]);
    free(rowSum);
    free(colSum);
    return 1;
}