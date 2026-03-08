int longestPalindrome(char * s) {
    int map[128] = {0};
    int len = 0;
    while (*s) {
        map[*s]++;
        s++;
    }
    int hasOdd = 0;
    for (int i = 0; i < 128; i++) {
        if (map[i] % 2 == 0) {
            len += map[i];
        } else {
            len += map[i] - 1;
            hasOdd = 1; 
        }
    }
    return len + hasOdd;
}