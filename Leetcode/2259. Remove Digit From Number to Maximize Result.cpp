char* removeDigit(char* number, char digit) {
    int n = strlen(number);
    int removeIdx = -1;
    
    for (int i = 0; i < n; i++) {
        if (number[i] == digit) {
            removeIdx = i;
            if (i + 1 < n && number[i] < number[i+1]) {
                break;
            }
        }
    }
    
    char* res = (char*)malloc(n * sizeof(char));
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (i == removeIdx) continue;
        res[k++] = number[i];
    }
    res[k] = '\0';
    return res;
}