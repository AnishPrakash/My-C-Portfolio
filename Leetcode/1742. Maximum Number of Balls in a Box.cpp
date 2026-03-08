int getSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int countBalls(int lowLimit, int highLimit) {
    int boxes[50] = {0};
    int maxBalls = 0;
    for (int i = lowLimit; i <= highLimit; i++) {
        int boxNum = getSum(i);
        boxes[boxNum]++;
        if (boxes[boxNum] > maxBalls) {
            maxBalls = boxes[boxNum];
        }
    }
    return maxBalls;
}