int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        n &= (n - 1);
        count++;
    }
    return count;
}

char** readBinaryWatch(int turnedOn, int* returnSize) {
    // Fix: Increase allocation size from 128 to 256 to prevent overflow
    char** result = (char**)malloc(256 * sizeof(char*)); 
    int count = 0;

    for (int h = 0; h < 12; h++) {
        for (int m = 0; m < 60; m++) {
            if (countSetBits(h) + countSetBits(m) == turnedOn) {
                result[count] = (char*)malloc(6 * sizeof(char));
                sprintf(result[count], "%d:%02d", h, m);
                count++;
            }
        }
    }

    *returnSize = count;
    return result;
}