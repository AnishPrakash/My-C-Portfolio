int countNegatives(int** grid, int gridSize, int* gridColSize) {
    int count = 0;
    int rows = gridSize;
    int cols = gridColSize[0];
    int i = 0;
    int j = cols - 1;
    while (i < rows && j >= 0) {
        if (grid[i][j] < 0) {
            count += (rows - i);
            j--;
        } else {
            i++;
        }
    }
    return count;
}