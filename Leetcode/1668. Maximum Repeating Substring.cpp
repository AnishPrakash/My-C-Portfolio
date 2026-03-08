#include <string.h>

int maxRepeating(char* sequence, char* word) {
    int ans = 0;
    int wlen = strlen(word);
    int slen = strlen(sequence);

    char temp[10001] = "";
    while (1) {
        strcat(temp, word);
        if (strstr(sequence, temp) == NULL) break;
        ans++;
    }

    return ans;
}
