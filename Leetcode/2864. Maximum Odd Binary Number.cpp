char* maximumOddBinaryNumber(char* s) {
    int n = strlen(s);
    int ones = 0;

    for(int i = 0; i < n; i++)
        if(s[i] == '1') ones++;

    for(int i = 0; i < n; i++)
        s[i] = '0';

    s[n - 1] = '1';
    ones--;

    for(int i = 0; i < ones; i++)
        s[i] = '1';

    return s;
}
