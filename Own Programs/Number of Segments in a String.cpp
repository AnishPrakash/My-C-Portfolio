int countSegments(char* s) {
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ') {
            if (i == 0 || s[i-1] == ' ') {
                count++;
            }
        }
    }
    return count;
}