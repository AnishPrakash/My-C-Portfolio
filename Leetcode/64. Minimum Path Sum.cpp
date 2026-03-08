int minPathSum(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    
    for (int i = 1; i < n; i++) {
        grid[0][i] += grid[0][i - 1];
    }
    
    for (int i = 1; i < m; i++) {
        grid[i][0] += grid[i - 1][0];
    }
    
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            int top = grid[i - 1][j];
            int left = grid[i][j - 1];
            grid[i][j] += (top < left) ? top : left;
        }
    }
    
    return grid[m - 1][n - 1];
}