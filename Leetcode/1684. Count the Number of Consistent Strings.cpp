int countConsistentStrings(char * allowed, char ** words, int wordsSize) {
    bool isAllowed[26] = {0};
    while (*allowed) {
        isAllowed[*allowed - 'a'] = true;
        allowed++;
    }
    int count = 0;
    for (int i = 0; i < wordsSize; i++) {
        bool consistent = true;
        char *w = words[i];
        while (*w) {
            if (!isAllowed[*w - 'a']) {
                consistent = false;
                break;
            }
            w++;
        }
        if (consistent) count++;
    }
    return count;
}