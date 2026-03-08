#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minCut(char* s) {
    int n = strlen(s);
    if (n == 0) return 0;
    
    int* dp = (int*)malloc((n + 1) * sizeof(int));
    bool** isPal = (bool**)malloc(n * sizeof(bool*));
    for(int i = 0; i < n; i++) {
        isPal[i] = (bool*)calloc(n, sizeof(bool));
    }
    
    for(int i = 0; i <= n; i++) {
        dp[i] = i - 1;
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            if(s[j] == s[i] && (i - j < 2 || isPal[j+1][i-1])) {
                isPal[j][i] = true;
                dp[i+1] = MIN(dp[i+1], dp[j] + 1);
            }
        }
    }
    
    int result = dp[n];
    
    free(dp);
    for(int i = 0; i < n; i++) free(isPal[i]);
    free(isPal);
    
    return result;
}