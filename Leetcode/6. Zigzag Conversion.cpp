#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    if (numRows == 1) return s;

    int len = strlen(s);
    char** rows = (char**)malloc(numRows * sizeof(char*));
    int* idx = (int*)calloc(numRows, sizeof(int));

    for (int i = 0; i < numRows; i++)
        rows[i] = (char*)malloc(len + 1);

    int cur = 0, dir = -1;

    for (int i = 0; i < len; i++) {
        rows[cur][idx[cur]++] = s[i];
        if (cur == 0 || cur == numRows - 1) dir = -dir;
        cur += dir;
    }

    char* res = (char*)malloc(len + 1);
    int k = 0;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < idx[i]; j++)
            res[k++] = rows[i][j];
    }

    res[k] = '\0';
    return res;
}
