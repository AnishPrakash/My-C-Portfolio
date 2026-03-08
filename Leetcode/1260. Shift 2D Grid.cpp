int** shiftGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes) {
    int m = gridSize;
    int n = *gridColSize;
    int total = m * n;
    k = k % total;
    
    int** result = (int**)malloc(m * sizeof(int*));
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    *returnSize = m;
    
    for (int i = 0; i < m; i++) {
        result[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int currentFlatIndex = i * n + j;
            int newFlatIndex = (currentFlatIndex + k) % total;
            int newRow = newFlatIndex / n;
            int newCol = newFlatIndex % n;
            result[newRow][newCol] = grid[i][j];
        }
    }
    
    return result;
}