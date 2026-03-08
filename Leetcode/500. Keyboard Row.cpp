#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

char** findWords(char** words, int wordsSize, int* returnSize) {
    int rows[26] = {
        2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3, 
        3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3
    };
    
    char** result = (char**)malloc(wordsSize * sizeof(char*));
    int count = 0;

    for (int i = 0; i < wordsSize; i++) {
        int len = strlen(words[i]);
        if (len == 0) continue;

        int firstRow = rows[tolower(words[i][0]) - 'a'];
        bool isValid = true;

        for (int j = 1; j < len; j++) {
            if (rows[tolower(words[i][j]) - 'a'] != firstRow) {
                isValid = false;
                break;
            }
        }

        if (isValid) {
            result[count] = words[i];
            count++;
        }
    }

    *returnSize = count;
    return result;
}