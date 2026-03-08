int* luckyNumbers (int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int m = matrixSize;
    int n = matrixColSize[0];
    int* minRow = (int*)malloc(m * sizeof(int));
    int* maxCol = (int*)malloc(n * sizeof(int));
    int* result = (int*)malloc(m * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < m; i++) {
        int minVal = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] < minVal) {
                minVal = matrix[i][j];
            }
        }
        minRow[i] = minVal;
    }

    for (int j = 0; j < n; j++) {
        int maxVal = INT_MIN;
        for (int i = 0; i < m; i++) {
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
            }
        }
        maxCol[j] = maxVal;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == minRow[i] && matrix[i][j] == maxCol[j]) {
                result[(*returnSize)++] = matrix[i][j];
            }
        }
    }

    free(minRow);
    free(maxCol);
    return result;
}