#define MIN(a, b) ((a) < (b) ? (a) : (b))
int nthUglyNumber(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;

    int* ugly = (int*)malloc(n * sizeof(int));
    ugly[0] = 1;

    int i2 = 0, i3 = 0, i5 = 0;
    
    for (int i = 1; i < n; i++) {
        int next2 = ugly[i2] * 2;
        int next3 = ugly[i3] * 3;
        int next5 = ugly[i5] * 5;
        
        int next = MIN(next2, MIN(next3, next5));
        ugly[i] = next;
        
        if (next == next2) i2++;
        if (next == next3) i3++;
        if (next == next5) i5++;
    }

    int result = ugly[n - 1];
    free(ugly);
    return result;
}