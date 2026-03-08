#define MAX(a, b) ((a) > (b) ? (a) : (b))
int maxDotProduct(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int* dp = (int*)malloc(nums2Size * sizeof(int));
    for (int j = 0; j < nums2Size; j++) {
        dp[j] = INT_MIN;
    }
    for (int i = 0; i < nums1Size; i++){
        int prev_diag = 0; 
        for (int j = 0; j < nums2Size; j++) {
            int product = nums1[i] * nums2[j];
            int temp_prev_row_val = dp[j];
            int use_curr = product;
            if (i > 0 && j > 0) {
                use_curr += MAX(0, prev_diag);
            }
            int skip_row = (i > 0) ? dp[j] : INT_MIN;
            int skip_col = (j > 0) ? dp[j-1] : INT_MIN;
            dp[j] = MAX(use_curr, MAX(skip_row, skip_col));
            prev_diag = temp_prev_row_val;
        }
    }
    int result = dp[nums2Size - 1];
    free(dp);
    return result;
}