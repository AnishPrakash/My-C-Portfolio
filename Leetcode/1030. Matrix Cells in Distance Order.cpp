typedef struct {
    int r;
    int c;
    int dist;
} Cell;

int compareCells(const void* a, const void* b) {
    return ((Cell*)a)->dist - ((Cell*)b)->dist;
}

int** allCellsDistOrder(int rows, int cols, int rCenter, int cCenter, int* returnSize, int** returnColumnSizes) {
    int count = rows * cols;
    Cell* cells = (Cell*)malloc(sizeof(Cell) * count);
    int k = 0;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cells[k].r = i;
            cells[k].c = j;
            cells[k].dist = abs(i - rCenter) + abs(j - cCenter);
            k++;
        }
    }
    
    qsort(cells, count, sizeof(Cell), compareCells);
    
    int** res = (int**)malloc(sizeof(int*) * count);
    *returnColumnSizes = (int*)malloc(sizeof(int) * count);
    *returnSize = count;
    
    for (int i = 0; i < count; i++) {
        res[i] = (int*)malloc(sizeof(int) * 2);
        res[i][0] = cells[i].r;
        res[i][1] = cells[i].c;
        (*returnColumnSizes)[i] = 2;
    }
    
    free(cells);
    return res;
}