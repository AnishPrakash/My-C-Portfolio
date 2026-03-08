typedef struct {
    int count;
    int index;
} RowInfo;

int cmp1337(const void* a, const void* b) {
    RowInfo* r1 = (RowInfo*)a;
    RowInfo* r2 = (RowInfo*)b;
    if (r1->count != r2->count) {
        return r1->count - r2->count;
    }
    return r1->index - r2->index;
}

int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize) {
    RowInfo* rows = (RowInfo*)malloc(matSize * sizeof(RowInfo));
    
    for (int i = 0; i < matSize; i++) {
        int count = 0;
        for (int j = 0; j < matColSize[i]; j++) {
            if (mat[i][j] == 1) count++;
            else break;
        }
        rows[i].count = count;
        rows[i].index = i;
    }
    
    qsort(rows, matSize, sizeof(RowInfo), cmp1337);
    
    int* res = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        res[i] = rows[i].index;
    }
    
    free(rows);
    *returnSize = k;
    return res;
}