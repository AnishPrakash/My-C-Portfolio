int cmp(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}
int uniqueMorseRepresentations(char** words, int wordsSize) {
    char* codes[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
        ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", 
        "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
    };
    char** transformations = (char**)malloc(wordsSize * sizeof(char*));
    for (int i = 0; i < wordsSize; i++) {
        transformations[i] = (char*)calloc(60, sizeof(char));
        int len = strlen(words[i]);
        for (int j = 0; j < len; j++) {
            strcat(transformations[i], codes[words[i][j] - 'a']);
        }
    }
    qsort(transformations, wordsSize, sizeof(char*), cmp);
    int uniqueCount = 0;
    if (wordsSize > 0) uniqueCount = 1;
    for (int i = 1; i < wordsSize; i++) {
        if (strcmp(transformations[i], transformations[i - 1]) != 0) {
            uniqueCount++;
        }
    }
    for (int i = 0; i < wordsSize; i++) {
        free(transformations[i]);
    }
    free(transformations);
    return uniqueCount;
}