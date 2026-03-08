int* mostVisited(int n, int* rounds, int roundsSize, int* returnSize) {
    int start = rounds[0];
    int end = rounds[roundsSize - 1];
    int* result;
    
    if (start <= end) {
        *returnSize = end - start + 1;
        result = (int*)malloc((*returnSize) * sizeof(int));
        for (int i = 0; i < *returnSize; i++) {
            result[i] = start + i;
        }
    } else {
        *returnSize = (n - start + 1) + end;
        result = (int*)malloc((*returnSize) * sizeof(int));
        int idx = 0;
        for (int i = 1; i <= end; i++) {
            result[idx++] = i;
        }
        for (int i = start; i <= n; i++) {
            result[idx++] = i;
        }
    }
    return result;
}