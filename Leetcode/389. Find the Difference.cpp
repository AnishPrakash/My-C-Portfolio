char findTheDifference(char* s, char* t) {
    int sum_s = 0;
    int sum_t = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        sum_s += s[i];
    }
    for (int i = 0; t[i] != '\0'; i++) {
        sum_t += t[i];
    }
    return (char)(sum_t - sum_s);
}