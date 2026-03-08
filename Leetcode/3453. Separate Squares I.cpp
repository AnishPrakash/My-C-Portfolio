double separateSquares(int** squares, int squaresSize, int* squaresColSize) {
    double totalArea = 0;
    double low = 2e9; 
    double high = 0;

    for (int i = 0; i < squaresSize; i++) {
        double y = squares[i][1];
        double l = squares[i][2];
        totalArea += l * l;
        if (y < low) low = y;
        if (y + l > high) high = y + l;
    }

    double target = totalArea / 2.0;

    for (int k = 0; k < 100; k++) {
        double mid = (low + high) / 2.0;
        double currentArea = 0;

        for (int i = 0; i < squaresSize; i++) {
            double y = squares[i][1];
            double l = squares[i][2];

            if (mid >= y + l) {
                currentArea += l * l;
            } else if (mid > y) {
                currentArea += l * (mid - y);
            }
        }

        if (currentArea < target) {
            low = mid;
        } else {
            high = mid;
        }
    }

    return high;
}