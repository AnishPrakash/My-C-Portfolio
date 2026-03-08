#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char* s, int low, int high) {
    while (low < high) {
        if (s[low++] != s[high--]) return false;
    }
    return true;
}

void backtrack(char* s, int start, int n, char**** res, int* resSize, int* capacity, int** colSizes, char** path, int pathSize) {
    if (start == n) {
        // Dynamic Resizing: If we run out of space, double the capacity
        if (*resSize >= *capacity) {
            *capacity *= 2;
            *res = (char***)realloc(*res, (*capacity) * sizeof(char**));
            *colSizes = (int*)realloc(*colSizes, (*capacity) * sizeof(int));
        }
        
        (*res)[*resSize] = (char**)malloc(pathSize * sizeof(char*));
        for (int i = 0; i < pathSize; i++) {
            (*res)[*resSize][i] = strdup(path[i]);
        }
        (*colSizes)[*resSize] = pathSize;
        (*resSize)++;
        return;
    }

    for (int end = start; end < n; end++) {
        if (isPalindrome(s, start, end)) {
            int len = end - start + 1;
            path[pathSize] = (char*)malloc((len + 1) * sizeof(char));
            strncpy(path[pathSize], s + start, len);
            path[pathSize][len] = '\0';

            backtrack(s, end + 1, n, res, resSize, capacity, colSizes, path, pathSize + 1);

            free(path[pathSize]); // Cleanup path for next branch
        }
    }
}

char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
    int n = strlen(s);
    int capacity = 100; // Start small and grow
    char*** res = (char***)malloc(capacity * sizeof(char**));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));
    char** path = (char**)malloc(n * sizeof(char*));
    *returnSize = 0;

    backtrack(s, 0, n, &res, returnSize, &capacity, returnColumnSizes, path, 0);

    free(path);
    return res;
}