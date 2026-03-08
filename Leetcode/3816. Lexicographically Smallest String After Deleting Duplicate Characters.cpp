#include <stdlib.h>
#include <string.h>

char* lexSmallestAfterDeletion(char* s) {
    int n = strlen(s);
    if (n == 0) return strdup("");

    int freq[26] = {0};
    for (int i = 0; i < n; i++) {
        freq[s[i] - 'a']++;
    }

    char* stack = (char*)malloc((n + 1) * sizeof(char));
    int top = -1;

    for (int i = 0; i < n; i++) {
        char c = s[i];
        while (top >= 0 && stack[top] > c && freq[stack[top] - 'a'] > 1) {
            freq[stack[top] - 'a']--; 
            top--;
        }
        stack[++top] = c;
    }

    while (top >= 0) {
        if (freq[stack[top] - 'a'] > 1) {
            freq[stack[top] - 'a']--;
            top--;
        } else {
            break; 
        }
    }

    stack[top + 1] = '\0';
    return stack;
}