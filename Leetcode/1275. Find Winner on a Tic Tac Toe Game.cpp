char* tictactoe(int** moves, int movesSize, int* movesColSize) {
    int rows[3] = {0};
    int cols[3] = {0};
    int diag = 0;
    int antiDiag = 0;
    
    for (int i = 0; i < movesSize; i++) {
        int r = moves[i][0];
        int c = moves[i][1];
        int val = (i % 2 == 0) ? 1 : -1;
        
        rows[r] += val;
        cols[c] += val;
        if (r == c) diag += val;
        if (r + c == 2) antiDiag += val;
        
        if (abs(rows[r]) == 3 || abs(cols[c]) == 3 || abs(diag) == 3 || abs(antiDiag) == 3) {
            return (i % 2 == 0) ? "A" : "B";
        }
    }
    
    return movesSize == 9 ? "Draw" : "Pending";
}