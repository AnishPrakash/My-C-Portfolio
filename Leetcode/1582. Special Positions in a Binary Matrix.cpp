int numSpecial(int** mat, int matSize, int* matColSize) {
    int m = matSize;
    int n = matColSize[0];
    int* rowSum = (int*)calloc(m, sizeof(int));
    int* colSum = (int*)calloc(n, sizeof(int));
    int count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1) {
                rowSum[i]++;
                colSum[j]++;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1 && rowSum[i] == 1 && colSum[j] == 1) {
                count++;
            }
        }
    }

    free(rowSum);
    free(colSum);
    return count;
}