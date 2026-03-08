typedef struct {
    char word[32];
    int count;
} WordCount;

int findIndex(WordCount* wc, int wcSize, char* word) {
    for(int i = 0; i < wcSize; i++) {
        if(strcmp(wc[i].word, word) == 0)
            return i;
    }
    return -1;
}

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    *returnSize = 0;
    if(wordsSize == 0) return NULL;

    int wlen = strlen(words[0]);
    int slen = strlen(s);
    int totalWords = wordsSize;

    // Build frequency map
    WordCount wc[1000];
    int wcSize = 0;

    for(int i = 0; i < wordsSize; i++) {
        int idx = findIndex(wc, wcSize, words[i]);
        if(idx == -1) {
            strcpy(wc[wcSize].word, words[i]);
            wc[wcSize].count = 1;
            wcSize++;
        } else {
            wc[idx].count++;
        }
    }

    int* res = (int*)malloc(sizeof(int) * slen);

    // Try each offset (0 .. wlen-1)
    for(int offset = 0; offset < wlen; offset++) {
        int left = offset;
        int count = 0;
        int seen[1000] = {0};

        for(int right = offset; right + wlen <= slen; right += wlen) {
            char temp[32];
            strncpy(temp, s + right, wlen);
            temp[wlen] = '\0';

            int idx = findIndex(wc, wcSize, temp);

            if(idx != -1) {
                seen[idx]++;
                count++;

                // shrink window if frequency exceeded
                while(seen[idx] > wc[idx].count) {
                    char leftWord[32];
                    strncpy(leftWord, s + left, wlen);
                    leftWord[wlen] = '\0';

                    int leftIdx = findIndex(wc, wcSize, leftWord);
                    seen[leftIdx]--;
                    count--;
                    left += wlen;
                }

                // valid window found
                if(count == totalWords) {
                    res[(*returnSize)++] = left;

                    // move left forward
                    char leftWord[32];
                    strncpy(leftWord, s + left, wlen);
                    leftWord[wlen] = '\0';
                    int leftIdx = findIndex(wc, wcSize, leftWord);
                    seen[leftIdx]--;
                    count--;
                    left += wlen;
                }

            } else {
                // reset window
                memset(seen, 0, sizeof(seen));
                count = 0;
                left = right + wlen;
            }
        }
    }

    return res;
}
