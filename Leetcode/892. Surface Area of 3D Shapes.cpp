int surfaceArea(int** grid, int gridSize, int* gridColSize) {
    int total = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] > 0) {
                total += 4 * grid[i][j] + 2;
                if (i > 0) total -= 2 * (grid[i][j] < grid[i - 1][j] ? grid[i][j] : grid[i - 1][j]);
                if (j > 0) total -= 2 * (grid[i][j] < grid[i][j - 1] ? grid[i][j] : grid[i][j - 1]);
            }
        }
    }
    return total;
}