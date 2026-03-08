#include <stdlib.h>

int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
    int** res = (int**)malloc((intervalsSize + 1) * sizeof(int*));
    *returnColumnSizes = (int*)malloc((intervalsSize + 1) * sizeof(int));
    
    int i = 0;
    int count = 0;
    
    while (i < intervalsSize && intervals[i][1] < newInterval[0]) {
        res[count] = (int*)malloc(2 * sizeof(int));
        res[count][0] = intervals[i][0];
        res[count][1] = intervals[i][1];
        (*returnColumnSizes)[count] = 2;
        count++;
        i++;
    }
    
    while (i < intervalsSize && intervals[i][0] <= newInterval[1]) {
        if (intervals[i][0] < newInterval[0]) newInterval[0] = intervals[i][0];
        if (intervals[i][1] > newInterval[1]) newInterval[1] = intervals[i][1];
        i++;
    }
    
    res[count] = (int*)malloc(2 * sizeof(int));
    res[count][0] = newInterval[0];
    res[count][1] = newInterval[1];
    (*returnColumnSizes)[count] = 2;
    count++;
    
    while (i < intervalsSize) {
        res[count] = (int*)malloc(2 * sizeof(int));
        res[count][0] = intervals[i][0];
        res[count][1] = intervals[i][1];
        (*returnColumnSizes)[count] = 2;
        count++;
        i++;
    }
    
    *returnSize = count;
    return res;
}