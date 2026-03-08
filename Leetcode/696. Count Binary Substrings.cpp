int min(int a, int b) {
    return a < b ? a : b;
}

int countBinarySubstrings(char* s) {
    int prevRunLength = 0;
    int curRunLength = 1;
    int res = 0;
    int len = strlen(s);

    for (int i = 1; i < len; i++) {
        if (s[i] == s[i - 1]) {
            curRunLength++;
        } else {
            res += min(prevRunLength, curRunLength);
            prevRunLength = curRunLength;
            curRunLength = 1;
        }
    }
    
    return res + min(prevRunLength, curRunLength);
}