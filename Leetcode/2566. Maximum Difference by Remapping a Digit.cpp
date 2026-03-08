int minMaxDifference(int num) {
    char s[20];
    sprintf(s, "%d", num);

    char toMax = 0;
    for(int i = 0; s[i]; i++) {
        if(s[i] != '9') {
            toMax = s[i];
            break;
        }
    }

    char maxStr[20];
    strcpy(maxStr, s);
    if(toMax) {
        for(int i = 0; maxStr[i]; i++)
            if(maxStr[i] == toMax) maxStr[i] = '9';
    }

    char toMin = s[0];
    char minStr[20];
    strcpy(minStr, s);
    for(int i = 0; minStr[i]; i++)
        if(minStr[i] == toMin) minStr[i] = '0';

    int mx = atoi(maxStr);
    int mn = atoi(minStr);

    return mx - mn;
}
