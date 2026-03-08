int minDeletionSize(char** strs, int strsSize) {
    int count = 0;
    int len = strlen(strs[0]);
    for (int col = 0; col < len; col++) {
        for (int row = 1; row < strsSize; row++) {
            if (strs[row][col] < strs[row - 1][col]) {
                count++;
                break;
            }
        }
    }
    return count;
}