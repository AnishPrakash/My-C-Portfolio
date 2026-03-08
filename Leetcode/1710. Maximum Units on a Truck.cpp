int compare(const void* a, const void* b) {
    return ((int**)b)[0][1] - ((int**)a)[0][1];
}

int maximumUnits(int** boxTypes, int boxTypesSize, int* boxTypesColSize, int truckSize) {
    qsort(boxTypes, boxTypesSize, sizeof(int*), compare);
    int maxUnits = 0;
    for (int i = 0; i < boxTypesSize && truckSize > 0; i++) {
        int count = boxTypes[i][0] < truckSize ? boxTypes[i][0] : truckSize;
        maxUnits += count * boxTypes[i][1];
        truckSize -= count;
    }
    return maxUnits;
}