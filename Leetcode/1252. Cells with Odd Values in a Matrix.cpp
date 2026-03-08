int oddCells(int m, int n, int** indices, int indicesSize, int* indicesColSize) {
    int* rowInc = (int*)calloc(m, sizeof(int));
    int* colInc = (int*)calloc(n, sizeof(int));
    
    for (int i = 0; i < indicesSize; i++) {
        rowInc[indices[i][0]]++;
        colInc[indices[i][1]]++;
    }
    
    int oddRows = 0;
    for (int i = 0; i < m; i++) {
        if (rowInc[i] % 2 != 0) oddRows++;
    }
    
    int oddCols = 0;
    for (int j = 0; j < n; j++) {
        if (colInc[j] % 2 != 0) oddCols++;
    }
    
    free(rowInc);
    free(colInc);
    
    return oddRows * (n - oddCols) + (m - oddRows) * oddCols;
}