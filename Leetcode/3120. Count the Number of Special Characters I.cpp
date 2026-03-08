int numberOfSpecialChars(char* word) {
    int hasLower[26] = {0};
    int hasUpper[26] = {0};
    for (int i = 0; word[i] != '\0'; i++) {
        if (islower(word[i])) {
            hasLower[word[i] - 'a'] = 1;
        } else if (isupper(word[i])) {
            hasUpper[word[i] - 'A'] = 1;
        }
    }
    int count = 0;
    for (int i = 0; i < 26; i++) {
        if (hasLower[i] && hasUpper[i]) {
            count++;
        }
    }
    return count;
}