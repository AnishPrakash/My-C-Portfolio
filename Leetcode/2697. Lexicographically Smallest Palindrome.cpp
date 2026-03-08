char* makeSmallestPalindrome(char* s) {
    int n = strlen(s);

    for(int i = 0; i < n / 2; i++) {
        char a = s[i];
        char b = s[n - 1 - i];
        if(a < b) s[n - 1 - i] = a;
        else s[i] = b;
    }
    return s;
}
