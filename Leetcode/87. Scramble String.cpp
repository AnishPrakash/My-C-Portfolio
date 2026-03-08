#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int memo[31][31][31];

int check(char* s1, char* s2, int i, int j, int len) {
    if (memo[i][j][len] != -1) {
        return memo[i][j][len];
    }

    if (len == 1) {
        return memo[i][j][len] = (s1[i] == s2[j]);
    }

    int count[26] = {0};
    for (int k = 0; k < len; k++) {
        count[s1[i + k] - 'a']++;
        count[s2[j + k] - 'a']--;
    }
    for (int k = 0; k < 26; k++) {
        if (count[k] != 0) {
            return memo[i][j][len] = 0;
        }
    }

    for (int k = 1; k < len; k++) {
        if ((check(s1, s2, i, j, k) && check(s1, s2, i + k, j + k, len - k)) ||
            (check(s1, s2, i, j + len - k, k) && check(s1, s2, i + k, j, len - k))) {
            return memo[i][j][len] = 1;
        }
    }

    return memo[i][j][len] = 0;
}

bool isScramble(char* s1, char* s2) {
    int n = strlen(s1);
    if (strlen(s2) != n) return false;

    memset(memo, -1, sizeof(memo));
    
    return check(s1, s2, 0, 0, n);
}