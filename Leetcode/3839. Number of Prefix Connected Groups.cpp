int compareStrings(const void *a, const void *b) {
    const char *strA = *(const char **)a;
    const char *strB = *(const char **)b;
    return strcmp(strA, strB);
}
int prefixConnected(char** words, int wordsSize, int k) {
    if (wordsSize < 2 || k <= 0) return 0;
    char** temp = words; 
    qsort(temp, wordsSize, sizeof(char*), compareStrings);
    int count = 0;
    int i = 0;
    while (i < wordsSize) {
        if (strlen(temp[i]) < k) {
            i++;
            continue;
        }
        int currentGroupSize = 1;
        int j = i + 1;
        while (j < wordsSize) {
            if (strlen(temp[j]) >= k && strncmp(temp[i], temp[j], k) == 0) {
                currentGroupSize++;
                j++;
            } else {
                break;
            }
        }
        if (currentGroupSize >= 2) {
            count++;
        }
        i = j;
    }
    return count;
}