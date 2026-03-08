int minTimeToType(char* word) {
    int res = 0;
    char curr = 'a';
    for (int i = 0; word[i] != '\0'; i++) {
        int diff = abs(word[i] - curr);
        res += (diff < 26 - diff ? diff : 26 - diff) + 1;
        curr = word[i];
    }
    return res;
}