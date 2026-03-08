int maxCount(int m, int n, int** ops, int opsSize, int* opsColSize) {
    int minA = m, minB = n;

    for (int i = 0; i < opsSize; i++) {
        if (ops[i][0] < minA) minA = ops[i][0];
        if (ops[i][1] < minB) minB = ops[i][1];
    }

    return minA * minB;
}
