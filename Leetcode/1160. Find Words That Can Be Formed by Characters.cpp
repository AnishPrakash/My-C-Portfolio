int countCharacters(char ** words, int wordsSize, char * chars) {
    int charCounts[26] = {0};
    int len = strlen(chars);
    for (int i = 0; i < len; i++) {
        charCounts[chars[i] - 'a']++;
    }
    
    int result = 0;
    for (int i = 0; i < wordsSize; i++) {
        int tempCounts[26] = {0};
        int wordLen = strlen(words[i]);
        bool canForm = true;
        
        for (int j = 0; j < wordLen; j++) {
            tempCounts[words[i][j] - 'a']++;
        }
        
        for (int k = 0; k < 26; k++) {
            if (tempCounts[k] > charCounts[k]) {
                canForm = false;
                break;
            }
        }
        
        if (canForm) {
            result += wordLen;
        }
    }
    return result;
}