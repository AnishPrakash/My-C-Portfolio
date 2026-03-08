#include <string.h>

void reverse(char* s, int left, int right) {
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

char* reverseWords(char* s) {
    int len = strlen(s);
    int read = 0, write = 0;

    while (read < len) {
        while (read < len && s[read] == ' ') read++;
        
        if (read < len) {
            if (write > 0) s[write++] = ' ';
            while (read < len && s[read] != ' ') {
                s[write++] = s[read++];
            }
        }
    }
    s[write] = '\0';

    reverse(s, 0, write - 1);

    int start = 0;
    for (int end = 0; end <= write; end++) {
        if (s[end] == ' ' || s[end] == '\0') {
            reverse(s, start, end - 1);
            start = end + 1;
        }
    }

    return s;
}