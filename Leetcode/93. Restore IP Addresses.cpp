#include <stdlib.h>
#include <string.h>

void dfs(char* s, int idx, int part, char* cur,
         char** res, int* size) {

    if(part == 4 && s[idx] == '\0') {
        res[*size] = strdup(cur);
        (*size)++;
        return;
    }
    if(part == 4 || s[idx] == '\0') return;

    int len = strlen(cur);

    for(int l = 1; l <= 3; l++) {
        if(!s[idx+l-1]) break;
        char seg[4];
        strncpy(seg, s+idx, l);
        seg[l] = '\0';

        if((l > 1 && seg[0]=='0') || atoi(seg) > 255) continue;

        if(part > 0) strcat(cur, ".");
        strcat(cur, seg);

        dfs(s, idx+l, part+1, cur, res, size);

        cur[len] = '\0';
    }
}

char** restoreIpAddresses(char* s, int* returnSize) {
    char** res = malloc(1000 * sizeof(char*));
    *returnSize = 0;
    char cur[100] = "";
    dfs(s, 0, 0, cur, res, returnSize);
    return res;
}
