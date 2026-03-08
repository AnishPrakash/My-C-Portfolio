
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int getMaxGap(int* bars, int size) {
    if (size == 0) return 1;
    qsort(bars, size, sizeof(int), compare);
    
    int maxCount = 1;
    int currentCount = 1;
    
    for (int i = 1; i < size; i++) {
        if (bars[i] == bars[i - 1] + 1) {
            currentCount++;
        } else {
            currentCount = 1;
        }
        if (currentCount > maxCount) {
            maxCount = currentCount;
        }
    }
    return maxCount + 1;
}

int maximizeSquareHoleArea(int n, int m, int* hBars, int hBarsSize, int* vBars, int vBarsSize) {
    int hGap = getMaxGap(hBars, hBarsSize);
    int vGap = getMaxGap(vBars, vBarsSize);
    int side = (hGap < vGap) ? hGap : vGap;
    return side * side;
}