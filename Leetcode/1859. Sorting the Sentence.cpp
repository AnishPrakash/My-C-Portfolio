char* sortSentence(char* s) {
    char* words[10] = {0};
    char* token = strtok(s, " ");
    int count = 0;
    
    while (token != NULL) {
        int len = strlen(token);
        int idx = token[len - 1] - '1';
        token[len - 1] = '\0';
        words[idx] = token;
        count++;
        token = strtok(NULL, " ");
    }
    
    char* res = (char*)malloc(200 * sizeof(char));
    res[0] = '\0';
    
    for (int i = 0; i < count; i++) {
        strcat(res, words[i]);
        if (i < count - 1) strcat(res, " ");
    }
    return res;
}