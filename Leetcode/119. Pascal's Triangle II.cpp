int* getRow(int rowIndex, int* returnSize) {
    int size = rowIndex + 1;
    int* row = (int*)malloc(size * sizeof(int));
    *returnSize = size;
    memset(row, 0, size * sizeof(int));
    row[0] = 1;
    for (int i = 1; i <= rowIndex; i++) {
        for (int j = i; j >= 1; j--) {
            row[j] += row[j - 1];
        }
    }
    return row;
}