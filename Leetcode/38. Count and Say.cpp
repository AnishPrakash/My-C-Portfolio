char* countAndSay(int n) {
    char* s = (char*)malloc(2);
    strcpy(s, "1");

    for (int i = 2; i <= n; i++) {
        char* temp = (char*)malloc(5000);
        int len = strlen(s);
        int idx = 0;

        for (int j = 0; j < len; j++) {
            int count = 1;
            while (j + 1 < len && s[j] == s[j + 1]) {
                count++;
                j++;
            }
            idx += sprintf(temp + idx, "%d%c", count, s[j]);
        }

        free(s);
        s = temp;
    }

    return s;
}
