int nearestValidPoint(int x, int y, int** points, int pointsSize, int* pointsColSize) {
    int min_dist = INT_MAX;
    int min_idx = -1;

    for (int i = 0; i < pointsSize; i++) {
        int px = points[i][0];
        int py = points[i][1];

        if (px == x || py == y) {
            int dist = abs(px - x) + abs(py - y);
            if (dist < min_dist) {
                min_dist = dist;
                min_idx = i;
            }
        }
    }

    return min_idx;
}