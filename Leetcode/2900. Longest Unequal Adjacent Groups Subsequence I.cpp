char** getLongestSubsequence(char** words, int wordsSize, int* groups, int groupsSize, int* returnSize) {
    char** res = (char**)malloc(wordsSize * sizeof(char*));
    int idx = 0;

    res[idx++] = words[0];
    int lastGroup = groups[0];

    for (int i = 1; i < wordsSize; i++) {
        if (groups[i] != lastGroup) {
            res[idx++] = words[i];
            lastGroup = groups[i];
        }
    }

    *returnSize = idx;
    return res;
}
