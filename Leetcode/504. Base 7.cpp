char* convertToBase7(int num) {
    if (num == 0) {
        char* res = (char*)malloc(2);
        res[0] = '0';
        res[1] = '\0';
        return res;
    }

    int n = abs(num);
    char buffer[20];
    int i = 0;

    while (n > 0) {
        buffer[i++] = (n % 7) + '0';
        n /= 7;
    }

    if (num < 0) {
        buffer[i++] = '-';
    }

    char* res = (char*)malloc(i + 1);
    for (int j = 0; j < i; j++) {
        res[j] = buffer[i - 1 - j];
    }
    res[i] = '\0';
    return res;
}