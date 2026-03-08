int cmp_1619(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

double trimMean(int* arr, int arrSize) {
    qsort(arr, arrSize, sizeof(int), cmp_1619);
    int remove = arrSize / 20;
    double sum = 0;
    
    for (int i = remove; i < arrSize - remove; i++) {
        sum += arr[i];
    }
    return sum / (arrSize - 2 * remove);
}