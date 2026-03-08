int* diStringMatch(char* s, int* returnSize) {
    int n = strlen(s);
    *returnSize = n + 1;
    int* res = (int*)malloc((n + 1) * sizeof(int));
    int low = 0;
    int high = n;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == 'I') {
            res[i] = low++;
        } else {
            res[i] = high--;
        }
    }
    res[n] = low;
    return res;
}