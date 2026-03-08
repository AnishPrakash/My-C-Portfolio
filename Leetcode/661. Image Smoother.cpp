#include <stdlib.h>

int** imageSmoother(int** img, int imgSize, int* imgColSize, int* returnSize, int** returnColumnSizes) {
    int m = imgSize;
    int n = imgColSize[0];
    
    int** res = (int**)malloc(m * sizeof(int*));
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    *returnSize = m;
    
    for (int i = 0; i < m; i++) {
        res[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
        
        for (int j = 0; j < n; j++) {
            int sum = 0;
            int count = 0;
            
            for (int r = i - 1; r <= i + 1; r++) {
                for (int c = j - 1; c <= j + 1; c++) {
                    if (r >= 0 && r < m && c >= 0 && c < n) {
                        sum += img[r][c];
                        count++;
                    }
                }
            }
            res[i][j] = sum / count;
        }
    }
    
    return res;
}