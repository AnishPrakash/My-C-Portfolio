int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if (matrixSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    int rows = matrixSize;
    int cols = matrixColSize[0];
    int total_elements = rows * cols;
    int* result = (int*)malloc(total_elements * sizeof(int));
    *returnSize = total_elements;
    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = cols - 1; 
    int index = 0;
    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) {
            result[index++] = matrix[top][j];
        }
        top++;
        for (int i = top; i <= bottom; i++) {
            result[index++] = matrix[i][right];
        }
        right--;
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                result[index++] = matrix[bottom][j];
            }
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result[index++] = matrix[i][left];
            }
            left++;
        }
    }
    return result;
}