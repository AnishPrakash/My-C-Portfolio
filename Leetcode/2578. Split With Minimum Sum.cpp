int cmpChar(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

int splitNum(int num) {
    char digits[20];
    sprintf(digits, "%d", num);

    int n = strlen(digits);
    qsort(digits, n, sizeof(char), cmpChar);

    int a = 0, b = 0;
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) a = a * 10 + (digits[i] - '0');
        else b = b * 10 + (digits[i] - '0');
    }
    return a + b;
}
