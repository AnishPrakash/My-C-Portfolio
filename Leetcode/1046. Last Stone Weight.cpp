int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int lastStoneWeight(int* stones, int stonesSize) {
    while (stonesSize > 1) {
        qsort(stones, stonesSize, sizeof(int), cmp);
        int y = stones[stonesSize - 1];
        int x = stones[stonesSize - 2];
        if (x == y) {
            stonesSize -= 2;
        } else {
            stones[stonesSize - 2] = y - x;
            stonesSize--;
        }
    }
    return stonesSize == 0 ? 0 : stones[0];
}