int cmpDesc2231(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int largestInteger(int num) {
    char s[15];
    sprintf(s, "%d", num);
    int len = strlen(s);
    
    int evens[15], odds[15];
    int eCount = 0, oCount = 0;
    
    for (int i = 0; i < len; i++) {
        int d = s[i] - '0';
        if (d % 2 == 0) evens[eCount++] = d;
        else odds[oCount++] = d;
    }
    
    qsort(evens, eCount, sizeof(int), cmpDesc2231);
    qsort(odds, oCount, sizeof(int), cmpDesc2231);
    
    int e = 0, o = 0;
    int res = 0;
    for (int i = 0; i < len; i++) {
        res *= 10;
        if ((s[i] - '0') % 2 == 0) res += evens[e++];
        else res += odds[o++];
    }
    
    return res;
}