int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    for (int i = triangleSize - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            int minVal = triangle[i+1][j] < triangle[i+1][j+1] ? triangle[i+1][j] : triangle[i+1][j+1];
            triangle[i][j] += minVal;
        }
    }
    return triangle[0][0];
}