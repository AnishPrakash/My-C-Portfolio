bool repeatedSubstringPattern(char* s) {
    int n = strlen(s);
    for (int i = n / 2; i >= 1; i--) {
        if (n % i == 0) {
            int j;
            for (j = i; j < n; j++) {
                if (s[j] != s[j - i]) {
                    break;
                }
            }
            if (j == n) {
                return true;
            }
        }
    }
    return false;
}