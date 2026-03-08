int countAsterisks(char* s) {
    int count = 0;
    bool insidePipe = false;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '|') {
            insidePipe = !insidePipe;
        } else if (s[i] == '*' && !insidePipe) {
            count++;
        }
    }
    return count;
}