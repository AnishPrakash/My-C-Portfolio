bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize) {
    int x0 = coordinates[0][0];
    int y0 = coordinates[0][1];
    int dx = coordinates[1][0] - x0;
    int dy = coordinates[1][1] - y0;
    
    for (int i = 2; i < coordinatesSize; i++) {
        int cx = coordinates[i][0] - x0;
        int cy = coordinates[i][1] - y0;
        if (dx * cy != dy * cx) {
            return false;
        }
    }
    
    return true;
}