char* getSmallestString(char* s) {
    int n = strlen(s);

    for(int i = 0; i < n - 1; i++) {
        int a = s[i] - '0';
        int b = s[i + 1] - '0';

        if(a > b && (a % 2 == b % 2)) {
            char temp = s[i];
            s[i] = s[i + 1];
            s[i + 1] = temp;
            break;
        }
    }
    return s;
}
