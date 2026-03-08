int minimumMoves(char* s) {
    int moves = 0, i = 0;
    int n = strlen(s);
    while (i < n) {
        if (s[i] == 'X') {
            moves++;
            i += 3;
        } else {
            i++;
        }
    }
    return moves;
}