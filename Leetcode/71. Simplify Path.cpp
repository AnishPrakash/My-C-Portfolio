char* simplifyPath(char* path) {
    int n = strlen(path);
    char** stack = (char**)malloc(sizeof(char*) * n);
    int top = -1;
    char* token = strtok(path, "/");
    while (token != NULL) {
        if (strcmp(token, "..") == 0) {
            if (top >= 0) top--; 
        } else if (strcmp(token, ".") != 0) {
            stack[++top] = token;
        }
        token = strtok(NULL, "/");
    }

    if (top == -1) return "/";

    char* result = (char*)malloc(sizeof(char*) * n + 1);
    result[0] = '\0';
    for (int i = 0; i <= top; i++) {
        strcat(result, "/");
        strcat(result, stack[i]);
    }
    return result;
}