char* licenseKeyFormatting(char* s, int k) {
    int n = strlen(s);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != '-') count++;
    }

    int dashes = (count > 0) ? (count - 1) / k : 0;
    int len = count + dashes;
    char* result = (char*)malloc(len + 1);
    result[len] = '\0';

    int r = len - 1;
    int curK = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] != '-') {
            result[r--] = toupper(s[i]);
            curK++;
            if (curK == k && r >= 0) {
                result[r--] = '-';
                curK = 0;
            }
        }
    }
    return result;
}