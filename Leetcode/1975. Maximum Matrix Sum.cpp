long long maxMatrixSum(int** matrix, int matrixSize, int* matrixColSize) {
    long long totalSum = 0;
    int negativeCount = 0;
    int minAbsValue = INT_MAX;
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[i]; j++) {
            int val = matrix[i][j];
            int absVal = abs(val);
            totalSum += absVal;
            if (val < 0) {
                negativeCount++;
            }
            if (absVal < minAbsValue) {
                minAbsValue = absVal;
            }
        }
    }
    if (negativeCount % 2 == 0) {
        return totalSum;
    } 
    else {
        return totalSum - 2 * minAbsValue;
    }
}