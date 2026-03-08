int projectionArea(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    int area = 0;

    // XY projection
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] > 0) area++;
        }
    }

    // XZ projection (row max)
    for (int i = 0; i < n; i++) {
        int mx = 0;
        for (int j = 0; j < n; j++) {
            if (grid[i][j] > mx) mx = grid[i][j];
        }
        area += mx;
    }

    // YZ projection (column max)
    for (int j = 0; j < n; j++) {
        int mx = 0;
        for (int i = 0; i < n; i++) {
            if (grid[i][j] > mx) mx = grid[i][j];
        }
        area += mx;
    }

    return area;
}
