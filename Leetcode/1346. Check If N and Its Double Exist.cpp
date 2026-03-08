int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int checkIfExist(int* arr, int arrSize) {
    qsort(arr, arrSize, sizeof(int), cmp);
    
    for (int i = 0; i < arrSize; i++) {
        int target = 2 * arr[i];
        int l = 0, r = arrSize - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == target && mid != i) {
                return 1;
            } else if (arr[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }
    return 0;
}