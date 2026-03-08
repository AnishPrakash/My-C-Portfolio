#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxProduct(char** words, int wordsSize) {
    int* masks = (int*)malloc(wordsSize * sizeof(int));
    int* lens = (int*)malloc(wordsSize * sizeof(int));
    
    for (int i = 0; i < wordsSize; i++) {
        int mask = 0;
        int len = 0;
        char* p = words[i];
        while (*p) {
            mask |= (1 << (*p - 'a'));
            len++;
            p++;
        }
        masks[i] = mask;
        lens[i] = len;
    }
    
    int maxVal = 0;
    for (int i = 0; i < wordsSize; i++) {
        for (int j = i + 1; j < wordsSize; j++) {
            if ((masks[i] & masks[j]) == 0) {
                int prod = lens[i] * lens[j];
                if (prod > maxVal) {
                    maxVal = prod;
                }
            }
        }
    }
    
    free(masks);
    free(lens);
    return maxVal;
}