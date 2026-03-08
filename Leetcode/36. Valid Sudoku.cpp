bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int rows[9][9] = {0};
    int cols[9][9] = {0};
    int boxes[9][9] = {0};
    
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (board[r][c] == '.') continue;
            
            int num = board[r][c] - '1';
            int boxIndex = (r / 3) * 3 + (c / 3);
            
            if (rows[r][num] || cols[c][num] || boxes[boxIndex][num]) {
                return false;
            }
            
            rows[r][num] = 1;
            cols[c][num] = 1;
            boxes[boxIndex][num] = 1;
        }
    }
    return true;
}