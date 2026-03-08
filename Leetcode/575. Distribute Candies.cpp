int compareIntegers(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
int distributeCandies(int* candyType, int candyTypeSize) {
    qsort(candyType, candyTypeSize, sizeof(int), compareIntegers);
    int uniqueCount = 1;
    for (int i = 1; i < candyTypeSize; i++) {
        if (candyType[i] != candyType[i - 1]) {
            uniqueCount++;
        }
    }
    int maxAllowed = candyTypeSize / 2;
    return (uniqueCount < maxAllowed) ? uniqueCount : maxAllowed;
}