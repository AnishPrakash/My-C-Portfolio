bool containsPattern(int* arr, int arrSize, int m, int k) {
    int count = 0;
    for (int i = 0; i + m < arrSize; i++) {
        if (arr[i] != arr[i + m]) {
            count = 0;
        } else {
            count++;
        }
        if (count == (k - 1) * m) {
            return true;
        }
    }
    return false;
}