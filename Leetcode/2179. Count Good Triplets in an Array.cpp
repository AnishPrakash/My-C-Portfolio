long long query(int* bit, int idx) {
    long long sum = 0;
    for (; idx > 0; idx -= idx & -idx) sum += bit[idx];
    return sum;
}

void update(int* bit, int n, int idx, int val) {
    for (; idx <= n; idx += idx & -idx) bit[idx] += val;
}

long long goodTriplets(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int n = nums1Size;
    int* pos = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) pos[nums1[i]] = i;
    
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) arr[i] = pos[nums2[i]];
    
    int* bit = (int*)calloc(n + 1, sizeof(int));
    long long ans = 0;
    
    for (int i = 0; i < n; i++) {
        long long left_smaller = query(bit, arr[i] + 1);
        long long right_larger = (n - 1 - arr[i]) - (i - left_smaller);
        
        ans += left_smaller * right_larger;
        update(bit, n, arr[i] + 1, 1);
    }
    
    free(pos);
    free(arr);
    free(bit);
    return ans;
}