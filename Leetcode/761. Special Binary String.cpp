#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int compareStrings(const void* a, const void* b) {
    return strcmp(*(const char**)b, *(const char**)a);
}

char* makeLargestSpecial(char* s) {
    int len = strlen(s);
    if (len == 0) {
        char* empty = (char*)malloc(1);
        empty[0] = '\0';
        return empty;
    }

    char** parts = (char**)malloc(sizeof(char*) * len);
    int partsCount = 0;
    int count = 0;
    int start = 0;

    for (int i = 0; i < len; i++) {
        count += (s[i] == '1') ? 1 : -1;
        
        if (count == 0) {
            int innerLen = i - start - 1;
            char* inner = (char*)malloc(innerLen + 1);
            strncpy(inner, s + start + 1, innerLen);
            inner[innerLen] = '\0';

            char* sortedInner = makeLargestSpecial(inner);
            free(inner);

            char* part = (char*)malloc(strlen(sortedInner) + 3);
            sprintf(part, "1%s0", sortedInner);
            free(sortedInner);

            parts[partsCount++] = part;
            start = i + 1;
        }
    }

    qsort(parts, partsCount, sizeof(char*), compareStrings);

    char* result = (char*)malloc(len + 1);
    result[0] = '\0';
    for (int i = 0; i < partsCount; i++) {
        strcat(result, parts[i]);
        free(parts[i]);
    }
    free(parts);

    return result;
}