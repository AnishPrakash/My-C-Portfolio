#include <stdlib.h>

int cmp(const void* a, const void* b) {
    int* ia = *(int**)a;
    int* ib = *(int**)b;
    return ia[0] - ib[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    if (intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    qsort(intervals, intervalsSize, sizeof(int*), cmp);
    
    int** res = (int**)malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));
    
    int count = 0;
    res[count] = (int*)malloc(2 * sizeof(int));
    res[count][0] = intervals[0][0];
    res[count][1] = intervals[0][1];
    (*returnColumnSizes)[count] = 2;
    count++;
    
    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] <= res[count - 1][1]) {
            if (intervals[i][1] > res[count - 1][1]) {
                res[count - 1][1] = intervals[i][1];
            }
        } else {
            res[count] = (int*)malloc(2 * sizeof(int));
            res[count][0] = intervals[i][0];
            res[count][1] = intervals[i][1];
            (*returnColumnSizes)[count] = 2;
            count++;
        }
    }
    
    *returnSize = count;
    return res;
}