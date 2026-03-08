typedef struct {
    char word[15];
    int count;
} WordCount;
int isBanned(char* word, char** banned, int bannedSize) {
    for (int i = 0; i < bannedSize; i++) {
        if (strcmp(word, banned[i]) == 0) return 1;
    }
    return 0;
}
char* mostCommonWord(char* paragraph, char** banned, int bannedSize) {
    int len = strlen(paragraph);
    for (int i = 0; i < len; i++) {
        if (isalpha(paragraph[i])) {
            paragraph[i] = tolower(paragraph[i]);
        } else {
            paragraph[i] = ' ';
        }
    }
    WordCount* counts = (WordCount*)malloc(1000 * sizeof(WordCount));
    int uniqueWords = 0;
    char* token = strtok(paragraph, " ");
    while (token != NULL) {
        if (!isBanned(token, banned, bannedSize)) {
            int found = -1;
            for (int i = 0; i < uniqueWords; i++) {
                if (strcmp(counts[i].word, token) == 0) {
                    found = i;
                    break;
                }
            }
            if (found != -1) {
                counts[found].count++;
            } else {
                strcpy(counts[uniqueWords].word, token);
                counts[uniqueWords].count = 1;
                uniqueWords++;
            }
        }
        token = strtok(NULL, " ");
    }
    int maxCount = 0;
    char* result = (char*)malloc(15 * sizeof(char));
    
    for (int i = 0; i < uniqueWords; i++) {
        if (counts[i].count > maxCount) {
            maxCount = counts[i].count;
            strcpy(result, counts[i].word);
        }
    }
    free(counts);
    return result;
}