int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0) return 0;
    int cols = matrixColSize[0];
    int maxArea = 0;
    int* heights = (int*)calloc(cols, sizeof(int));
    int* stack = (int*)malloc((cols + 1) * sizeof(int));
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == '1') {
                heights[j] += 1;
            } else {
                heights[j] = 0;
            }
        }
        int top = -1;
        for (int j = 0; j <= cols; j++) {
            int h = (j == cols) ? 0 : heights[j];
            while (top != -1 && heights[stack[top]] >= h) {
                int height = heights[stack[top--]]; 
                int width = (top == -1) ? j : j - stack[top] - 1;
                int currentArea = height * width;
                if (currentArea > maxArea) {
                    maxArea = currentArea;
                }
            }
            stack[++top] = j;
        }
    }
    free(heights);
    free(stack);
    return maxArea;
}