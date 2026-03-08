void backtrack(int n, int k, int start, int* current, int currentSize, int** result, int* returnSize, int** returnColumnSizes) {
    if (currentSize == k) {
        result[*returnSize] = (int*)malloc(k * sizeof(int));
        for (int i = 0; i < k; i++) {
            result[*returnSize][i] = current[i];
        }
        (*returnColumnSizes)[*returnSize] = k;
        (*returnSize)++;
        return;
    }
    for (int i = start; i <= n; i++) {
        current[currentSize] = i;
        backtrack(n, k, i + 1, current, currentSize + 1, result, returnSize, returnColumnSizes);
    }
}
int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
    long long combinations = 1;
    for (int i = 1; i <= k; i++) {
        combinations = combinations * (n - i + 1) / i;
    }
    int** result = (int**)malloc(combinations * sizeof(int*));
    *returnColumnSizes = (int*)malloc(combinations * sizeof(int));
    *returnSize = 0;
    int* current = (int*)malloc(k * sizeof(int));
    backtrack(n, k, 1, current, 0, result, returnSize, returnColumnSizes);
    free(current);
    return result;
}