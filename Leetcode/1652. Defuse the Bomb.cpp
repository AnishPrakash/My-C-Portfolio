int* decrypt(int* code, int codeSize, int k, int* returnSize) {
    *returnSize = codeSize;
    int* result = (int*)calloc(codeSize, sizeof(int));
    if (k == 0) return result;
    
    for (int i = 0; i < codeSize; i++) {
        int sum = 0;
        if (k > 0) {
            for (int j = 1; j <= k; j++) {
                sum += code[(i + j) % codeSize];
            }
        } else {
            for (int j = 1; j <= -k; j++) {
                sum += code[(i - j + codeSize) % codeSize];
            }
        }
        result[i] = sum;
    }
    return result;
}