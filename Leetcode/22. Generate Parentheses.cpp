#include <stdio.h>
#include <stdlib.h>

void backtrack(char** res, int* returnSize, char* cur, int pos, int open, int close, int n) {
    if (pos == 2 * n) {
        res[*returnSize] = strdup(cur);
        (*returnSize)++;
        return;
    }

    if (open < n) {
        cur[pos] = '(';
        backtrack(res, returnSize, cur, pos + 1, open + 1, close, n);
    }
    if (close < open) {
        cur[pos] = ')';
        backtrack(res, returnSize, cur, pos + 1, open, close + 1, n);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    char** res = (char**)malloc(10000 * sizeof(char*));
    char* cur = (char*)malloc(2 * n + 1);
    cur[2 * n] = '\0';
    *returnSize = 0;

    backtrack(res, returnSize, cur, 0, 0, 0, n);
    return res;
}
