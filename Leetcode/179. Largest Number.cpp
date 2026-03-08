#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
    const char* str1 = *(const char**)a;
    const char* str2 = *(const char**)b;
    
    char buffer1[256];
    char buffer2[256];
    
    strcpy(buffer1, str1);
    strcat(buffer1, str2);
    
    strcpy(buffer2, str2);
    strcat(buffer2, str1);
    
    return strcmp(buffer2, buffer1); 
}

char* largestNumber(int* nums, int numsSize) {
    char** strs = (char**)malloc(numsSize * sizeof(char*));
    int total_len = 0;
    
    for (int i = 0; i < numsSize; i++) {
        strs[i] = (char*)malloc(12 * sizeof(char));
        sprintf(strs[i], "%d", nums[i]);
        total_len += strlen(strs[i]);
    }
    
    qsort(strs, numsSize, sizeof(char*), compare);
    
    if (strs[0][0] == '0') {
        char* ans = (char*)malloc(2);
        strcpy(ans, "0");
        return ans;
    }
    
    char* result = (char*)malloc((total_len + 1) * sizeof(char));
    result[0] = '\0';
    
    for (int i = 0; i < numsSize; i++) {
        strcat(result, strs[i]);
        free(strs[i]);
    }
    free(strs);
    
    return result;
}