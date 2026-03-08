int titleToNumber(char* columnTitle) {
    long long res = 0;
    for (int i = 0; columnTitle[i] != '\0'; i++) {
        int val = columnTitle[i] - 'A' + 1;
        res = res * 26 + val;
    }
    return (int)res;
}