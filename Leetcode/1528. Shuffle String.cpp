char* restoreString(char* s, int* indices, int indicesSize) {
    int len = strlen(s);
    char* result = (char*)malloc((len + 1) * sizeof(char));
    
    for (int i = 0; i < len; i++) {
        result[indices[i]] = s[i];
    }
    result[len] = '\0';
    return result;
}