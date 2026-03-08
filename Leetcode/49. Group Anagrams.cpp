#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpChar(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

char* sortString(char* s) {
    char* temp = strdup(s);
    qsort(temp, strlen(temp), sizeof(char), cmpChar);
    return temp;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    char** keys = (char**)malloc(strsSize * sizeof(char*));
    int* groupIndex = (int*)malloc(strsSize * sizeof(int));
    
    char*** result = (char***)malloc(strsSize * sizeof(char**));
    *returnColumnSizes = (int*)malloc(strsSize * sizeof(int));
    
    int groups = 0;
    
    for (int i = 0; i < strsSize; i++) {
        keys[i] = sortString(strs[i]);
        int found = -1;
        
        for (int j = 0; j < groups; j++) {
            if (strcmp(keys[i], keys[groupIndex[j]]) == 0) {
                found = j;
                break;
            }
        }
        
        if (found == -1) {
            groupIndex[groups] = i;
            result[groups] = (char**)malloc(strsSize * sizeof(char*));
            (*returnColumnSizes)[groups] = 0;
            found = groups++;
        }
        
        result[found][(*returnColumnSizes)[found]++] = strs[i];
    }
    
    *returnSize = groups;
    
    return result;
}
