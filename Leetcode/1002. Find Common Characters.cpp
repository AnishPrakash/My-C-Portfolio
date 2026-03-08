char ** commonChars(char ** words, int wordsSize, int* returnSize) {
    int min_freq[26];
    for (int i = 0; i < 26; i++) min_freq[i] = INT_MAX;
    
    for (int i = 0; i < wordsSize; i++) {
        int freq[26] = {0};
        int len = strlen(words[i]);
        for (int j = 0; j < len; j++) {
            freq[words[i][j] - 'a']++;
        }
        for (int j = 0; j < 26; j++) {
            if (freq[j] < min_freq[j]) {
                min_freq[j] = freq[j];
            }
        }
    }
    
    int total = 0;
    for (int i = 0; i < 26; i++) total += min_freq[i];
    
    char ** result = (char **)malloc(total * sizeof(char *));
    *returnSize = total;
    int k = 0;
    
    for (int i = 0; i < 26; i++) {
        while (min_freq[i] > 0) {
            result[k] = (char *)malloc(2 * sizeof(char));
            result[k][0] = i + 'a';
            result[k][1] = '\0';
            k++;
            min_freq[i]--;
        }
    }
    return result;
}