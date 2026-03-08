bool arrayStringsAreEqual(char ** word1, int word1Size, char ** word2, int word2Size) {
    int i = 0, j = 0;
    int m = 0, n = 0;
    
    while (i < word1Size && j < word2Size) {
        if (word1[i][m++] != word2[j][n++]) return false;
        if (word1[i][m] == '\0') {
            i++;
            m = 0;
        }
        if (word2[j][n] == '\0') {
            j++;
            n = 0;
        }
    }
    return i == word1Size && j == word2Size;
}