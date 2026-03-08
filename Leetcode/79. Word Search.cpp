#include <stdbool.h>

bool dfs(char** board, int r, int c, int rows, int cols, char* word, int idx) {
    if(word[idx] == '\0') return true;
    if(r<0 || c<0 || r>=rows || c>=cols || board[r][c]!=word[idx]) return false;

    char temp = board[r][c];
    board[r][c] = '#';

    bool found = dfs(board,r+1,c,rows,cols,word,idx+1) ||
                 dfs(board,r-1,c,rows,cols,word,idx+1) ||
                 dfs(board,r,c+1,rows,cols,word,idx+1) ||
                 dfs(board,r,c-1,rows,cols,word,idx+1);

    board[r][c] = temp;
    return found;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int rows = boardSize, cols = boardColSize[0];

    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            if(dfs(board,i,j,rows,cols,word,0))
                return true;
    return false;
}
