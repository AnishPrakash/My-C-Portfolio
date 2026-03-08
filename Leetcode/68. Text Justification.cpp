char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
    char** res = (char**)malloc(sizeof(char*) * wordsSize);
    *returnSize = 0;

    int i = 0;
    while(i < wordsSize) {
        int j = i, len = 0;

        while(j < wordsSize && len + strlen(words[j]) + (j - i) <= maxWidth) {
            len += strlen(words[j]);
            j++;
        }

        int spaces = maxWidth - len;
        int gaps = j - i - 1;

        char* line = (char*)malloc(maxWidth + 1);
        int pos = 0;

        if(j == wordsSize || gaps == 0) {
            for(int k = i; k < j; k++) {
                strcpy(line + pos, words[k]);
                pos += strlen(words[k]);
                if(k < j - 1) line[pos++] = ' ';
            }
            while(pos < maxWidth) line[pos++] = ' ';
        } 
        else {
            int even = spaces / gaps;
            int extra = spaces % gaps;

            for(int k = i; k < j; k++) {
                strcpy(line + pos, words[k]);
                pos += strlen(words[k]);
                if(k < j - 1) {
                    int sp = even + (extra-- > 0);
                    while(sp--) line[pos++] = ' ';
                }
            }
        }

        line[maxWidth] = '\0';
        res[(*returnSize)++] = line;
        i = j;
    }

    return res;
}
