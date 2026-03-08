int numRookCaptures(char** board, int boardSize, int* boardColSize) {
    int x, y, res = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] == 'R') {
                x = i;
                y = j;
                break;
            }
        }
    }
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    for (int i = 0; i < 4; ++i) {
        for (int step = 1; ; ++step) {
            int nx = x + dx[i] * step;
            int ny = y + dy[i] * step;
            if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8 || board[nx][ny] == 'B') break;
            if (board[nx][ny] == 'p') {
                res++;
                break;
            }
        }
    }
    return res;
}