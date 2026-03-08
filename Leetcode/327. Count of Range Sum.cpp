#include <stdio.h>
#include <stdlib.h>

int mergeSortCount(long long* sums, int start, int end, int lower, int upper) {
    if (end - start <= 1) return 0;
    int mid = (start + end) / 2;
    int count = mergeSortCount(sums, start, mid, lower, upper) + 
                mergeSortCount(sums, mid, end, lower, upper);
    
    int j = mid, k = mid, t = mid;
    long long* cache = (long long*)malloc((end - start) * sizeof(long long));
    int r = 0;

    for (int i = start; i < mid; i++) {
        while (k < end && sums[k] - sums[i] < lower) k++;
        while (j < end && sums[j] - sums[i] <= upper) j++;
        while (t < end && sums[t] < sums[i]) cache[r++] = sums[t++];
        cache[r++] = sums[i];
        count += j - k;
    }
    
    while (t < end) cache[r++] = sums[t++];
    for (int i = 0; i < r; i++) sums[start + i] = cache[i];
    
    free(cache);
    return count;
}

int countRangeSum(int* nums, int numsSize, int lower, int upper) {
    long long* sums = (long long*)malloc((numsSize + 1) * sizeof(long long));
    sums[0] = 0;
    for (int i = 0; i < numsSize; i++) {
        sums[i + 1] = sums[i] + nums[i];
    }
    
    int ans = mergeSortCount(sums, 0, numsSize + 1, lower, upper);
    free(sums);
    return ans;
}