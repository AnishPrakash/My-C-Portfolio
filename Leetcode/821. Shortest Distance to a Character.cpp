#define MAX_DIST 20000
int* shortestToChar(char * s, char c, int* returnSize) {
    int n = strlen(s);
    int* result = (int*)malloc(n * sizeof(int));
    *returnSize = n;
    int prev = -MAX_DIST;
    for (int i = 0; i < n; i++) {
        if (s[i] == c) {
            prev = i;
        }
        result[i] = i - prev;
    }
    prev = MAX_DIST * 2;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == c) {
            prev = i;
        }
        int dist = abs(prev - i);
        if (dist < result[i]) {
            result[i] = dist;
        }
    }
    return result;
}