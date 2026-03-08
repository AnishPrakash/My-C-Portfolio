int minLength(int* nums, int n, int k) {
    int m[100001] = {0}, l = 0, res = n + 1;
    long long sum = 0;
    for (int r = 0; r < n; r++) {
        if (m[nums[r]]++ == 0) sum += nums[r];
        while (sum >= k) {
            if (r - l + 1 < res) res = r - l + 1;
            if (--m[nums[l]] == 0) sum -= nums[l];
            l++;
        }
    }
    return res > n ? -1 : res;
}