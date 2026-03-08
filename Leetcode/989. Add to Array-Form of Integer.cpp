int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {
    int* res = (int*)malloc(sizeof(int) * (numSize + 11));
    int idx = 0;
    int i = numSize - 1;
    
    while (i >= 0 || k > 0) {
        if (i >= 0) {
            k += num[i];
            i--;
        }
        res[idx++] = k % 10;
        k /= 10;
    }
    
    for (int l = 0, r = idx - 1; l < r; l++, r--) {
        int temp = res[l];
        res[l] = res[r];
        res[r] = temp;
    }
    
    *returnSize = idx;
    return res;
}