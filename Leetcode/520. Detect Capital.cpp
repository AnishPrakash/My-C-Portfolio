bool detectCapitalUse(char* word) {
    int count = 0;
    int k = strlen(word);
    for (int i = 0; i < k; i++) {
        if (isupper(word[i])) {
            count++;
        }
    }
    return (count == k) || (count == 0) || (count == 1 && isupper(word[0]));
}