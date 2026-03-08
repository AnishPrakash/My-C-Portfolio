#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** findRepeatedDnaSequences(char* s, int* returnSize) {
    int len = strlen(s);
    if (len <= 10) {
        *returnSize = 0;
        return NULL;
    }

    char** result = (char**)malloc(len * sizeof(char*));
    int count = 0;
    
    int map[1048576] = {0}; 
    int current = 0;
    
    for (int i = 0; i < 9; i++) {
        current = (current << 2) | ((s[i] >> 1) & 3);
    }
    
    for (int i = 9; i < len; i++) {
        current = ((current << 2) & 0xFFFFF) | ((s[i] >> 1) & 3);
        
        if (map[current] == 1) {
            result[count] = (char*)malloc(11 * sizeof(char));
            strncpy(result[count], s + i - 9, 10);
            result[count][10] = '\0';
            count++;
            map[current] = 2; 
        } else if (map[current] == 0) {
            map[current] = 1;
        }
    }
    
    *returnSize = count;
    return result;
}