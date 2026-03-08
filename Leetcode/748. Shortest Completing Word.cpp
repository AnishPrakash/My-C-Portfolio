char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize) {
    int target[26] = {0};
    for (int i = 0; licensePlate[i]; i++) {
        if (isalpha(licensePlate[i])) {
            target[tolower(licensePlate[i]) - 'a']++;
        }
    }
    
    char* result = NULL;
    
    for (int i = 0; i < wordsSize; i++) {
        int current[26] = {0};
        for (int j = 0; words[i][j]; j++) {
            current[words[i][j] - 'a']++;
        }
        
        int valid = 1;
        for (int k = 0; k < 26; k++) {
            if (current[k] < target[k]) {
                valid = 0;
                break;
            }
        }
        
        if (valid) {
            if (result == NULL || strlen(words[i]) < strlen(result)) {
                result = words[i];
            }
        }
    }
    
    return result;
}