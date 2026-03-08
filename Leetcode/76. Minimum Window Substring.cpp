#include <string.h>
#include <limits.h>
#include <stdlib.h>

char* minWindow(char* s, char* t) {
    if (!s || !t || strlen(s) == 0 || strlen(t) == 0) {
        return "";
    }

    int map[128] = {0};
    int t_len = strlen(t);
    int s_len = strlen(s);

    for (int i = 0; i < t_len; i++) {
        map[t[i]]++;
    }

    int count = t_len;
    int start = 0, end = 0;
    int min_len = INT_MAX;
    int min_start = 0;

    while (end < s_len) {
        if (map[s[end]] > 0) {
            count--;
        }
        map[s[end]]--;
        end++;

        while (count == 0) {
            if (end - start < min_len) {
                min_start = start;
                min_len = end - start;
            }

            map[s[start]]++;
            if (map[s[start]] > 0) {
                count++;
            }
            start++;
        }
    }

    if (min_len == INT_MAX) {
        return "";
    }

    char* result = (char*)malloc((min_len + 1) * sizeof(char));
    strncpy(result, s + min_start, min_len);
    result[min_len] = '\0';

    return result;
}