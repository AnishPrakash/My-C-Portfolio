int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize) {
    int counts[100] = {0};
    int res = 0;
    for (int i = 0; i < dominoesSize; i++) {
        int a = dominoes[i][0];
        int b = dominoes[i][1];
        int val = (a < b) ? a * 10 + b : b * 10 + a;
        res += counts[val];
        counts[val]++;
    }
    return res;
}