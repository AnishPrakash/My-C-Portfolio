int cmp_1637(const void* a, const void* b) {
    int* p1 = *(int**)a;
    int* p2 = *(int**)b;
    return p1[0] - p2[0];
}

int maxWidthOfVerticalArea(int** points, int pointsSize, int* pointsColSize) {
    qsort(points, pointsSize, sizeof(int*), cmp_1637);
    int maxW = 0;
    
    for (int i = 1; i < pointsSize; i++) {
        int w = points[i][0] - points[i-1][0];
        if (w > maxW) maxW = w;
    }
    return maxW;
}