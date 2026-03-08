#include <stdlib.h>

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    int** matrix = (int**)malloc(n * sizeof(int*));
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
    }
    
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    int val = 1;
    
    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) {
            matrix[top][j] = val++;
        }
        top++;
        
        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = val++;
        }
        right--;
        
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                matrix[bottom][j] = val++;
            }
            bottom--;
        }
        
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = val++;
            }
            left++;
        }
    }
    
    *returnSize = n;
    return matrix;
}