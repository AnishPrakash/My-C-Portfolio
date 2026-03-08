#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getHint(char* secret, char* guess) {
    int bulls = 0;
    int cows = 0;
    int s_counts[10] = {0};
    int g_counts[10] = {0};
    int len = strlen(secret);

    for (int i = 0; i < len; i++) {
        if (secret[i] == guess[i]) {
            bulls++;
        } else {
            s_counts[secret[i] - '0']++;
            g_counts[guess[i] - '0']++;
        }
    }

    for (int i = 0; i < 10; i++) {
        int s = s_counts[i];
        int g = g_counts[i];
        cows += (s < g ? s : g);
    }

    char* result = (char*)malloc(16 * sizeof(char));
    sprintf(result, "%dA%dB", bulls, cows);
    
    return result;
}