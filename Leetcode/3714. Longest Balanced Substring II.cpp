#define MAX(a, b) ((a) > (b) ? (a) : (b))
int solve1(char *s, int n) {
    int max_len = 0;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        cur++;
        if (i == n - 1 || s[i] != s[i + 1]) {
            if (cur > max_len) max_len = cur;
            cur = 0;
        }
    }
    return max_len;
}
int solve2(char *s, int n, char c1, char c2, char forbidden) {
    int buf_size = 2 * n + 1;
    int *pos = (int *)malloc(buf_size * sizeof(int));
    int *cookie = (int *)calloc(buf_size, sizeof(int)); 
    int current_cookie = 0;
    int max_len = 0;
    int i = 0;
    int offset = n;
    while (i < n) {
        if (s[i] == forbidden) {
            i++;
            continue;
        }
        current_cookie++;
        int bal = 0;
        pos[offset] = i - 1;
        cookie[offset] = current_cookie;
        while (i < n && s[i] != forbidden) {
            if (s[i] == c1) bal++;
            else if (s[i] == c2) bal--;
            int idx = bal + offset;
            if (cookie[idx] == current_cookie) {
                int len = i - pos[idx];
                if (len > max_len) max_len = len;
            } else {
                pos[idx] = i;
                cookie[idx] = current_cookie;
            }
            i++;
        }
    }
    free(pos);
    free(cookie);
    return max_len;
}
typedef struct {
    int d1;
    int d2;
    int index;
    int filled; 
} HashEntry;
int solve3(char *s, int n) {
    int size = 1;
    while (size <= n) size <<= 1;
    size <<= 2;
    int mask = size - 1;
    HashEntry *table = (HashEntry *)calloc(size, sizeof(HashEntry));
    int a = 0, b = 0, c = 0;
    int max_len = 0;
    table[0].d1 = 0;
    table[0].d2 = 0;
    table[0].index = -1;
    table[0].filled = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') a++;
        else if (s[i] == 'b') b++;
        else if (s[i] == 'c') c++;
        int d1 = a - b;
        int d2 = b - c;
        unsigned int key = (unsigned int)d1 * 73856093 ^ (unsigned int)d2 * 19349663;
        int slot = key & mask;
        while (table[slot].filled) {
            if (table[slot].d1 == d1 && table[slot].d2 == d2) {
                int len = i - table[slot].index;
                if (len > max_len) max_len = len;
                goto next_iter; 
            }
            slot = (slot + 1) & mask;
        }
        table[slot].d1 = d1;
        table[slot].d2 = d2;
        table[slot].index = i;
        table[slot].filled = 1;
        next_iter:;
    }
    free(table);
    return max_len;
}
int longestBalanced(char* s) {
    int n = strlen(s);
    if (n == 0) return 0;
    int ans = 0;
    ans = MAX(ans, solve1(s, n));
    ans = MAX(ans, solve2(s, n, 'a', 'b', 'c'));
    ans = MAX(ans, solve2(s, n, 'b', 'c', 'a'));
    ans = MAX(ans, solve2(s, n, 'a', 'c', 'b'));
    ans = MAX(ans, solve3(s, n));
    return ans;
}