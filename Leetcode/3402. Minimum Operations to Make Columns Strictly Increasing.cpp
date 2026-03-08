int minimumOperations(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = gridColSize[0];

    int ops = 0;

    for(int c = 0; c < cols; c++) {
        for(int r = 1; r < rows; r++) {
            if(grid[r][c] <= grid[r - 1][c]) {
                int need = grid[r - 1][c] + 1;
                ops += (need - grid[r][c]);
                grid[r][c] = need;
            }
        }
    }
    return ops;
}
