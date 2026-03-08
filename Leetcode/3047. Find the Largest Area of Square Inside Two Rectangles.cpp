#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
long long largestSquareArea(int** bottomLeft, int bottomLeftSize, int* bottomLeftColSize, int** topRight, int topRightSize, int* topRightColSize) {
    long long maxSide = 0;
    for (int i = 0; i < bottomLeftSize; i++) {
        for (int j = i + 1; j < bottomLeftSize; j++) {        
            int x1 = MAX(bottomLeft[i][0], bottomLeft[j][0]);
            int y1 = MAX(bottomLeft[i][1], bottomLeft[j][1]);
            int x2 = MIN(topRight[i][0], topRight[j][0]);
            int y2 = MIN(topRight[i][1], topRight[j][1]);       
            int width = x2 - x1;
            int height = y2 - y1;           
            if (width > 0 && height > 0) {
                int side = MIN(width, height); 
                if (side > maxSide) {
                    maxSide = side;
                }
            }
        }
    }
    return maxSide * maxSide;
}