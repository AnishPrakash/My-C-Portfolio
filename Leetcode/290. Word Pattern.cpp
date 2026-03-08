bool wordPattern(char* pattern, char* s) {
    char* map[256] = {0}; 
    char* used[256] = {0};   
    char* token = strtok(s, " ");
    int i = 0;
    while (token) {
        if (pattern[i] == '\0')
            return false;
        unsigned char c = pattern[i];
        if (map[c] == NULL) {
            for (int k = 0; k < 256; k++) {
                if (used[k] && strcmp(used[k], token) == 0)
                    return false;
            }
            map[c] = token;
            used[i] = token;
        } else {
            if (strcmp(map[c], token) != 0)
                return false;
        }
        token = strtok(NULL, " ");
        i++;
    }
    return pattern[i] == '\0';
}
