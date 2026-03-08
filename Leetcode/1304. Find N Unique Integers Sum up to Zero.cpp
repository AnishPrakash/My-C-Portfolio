int* sumZero(int n, int* returnSize) {
    *returnSize = n;
    int* result = (int*)malloc(n * sizeof(int));
    int index = 0;
    
    for (int i = 1; i <= n / 2; i++) {
        result[index++] = i;
        result[index++] = -i;
    }
    
    if (n % 2 != 0) {
        result[index] = 0;
    }
    
    return result;
}