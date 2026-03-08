#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long long maxSumTrionic(int* nums, int numsSize) {
    int n = numsSize;
    if (n < 4) return 0;

    long long* L = (long long*)malloc(n * sizeof(long long));
    long long* R = (long long*)malloc(n * sizeof(long long));

    L[0] = nums[0];
    for (int i = 1; i < n; i++) {
        if (nums[i] > nums[i - 1]) {
            L[i] = nums[i] + (L[i - 1] > 0 ? L[i - 1] : 0);
        } else {
            L[i] = nums[i];
        }
    }

    R[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            R[i] = nums[i] + (R[i + 1] > 0 ? R[i + 1] : 0);
        } else {
            R[i] = nums[i];
        }
    }

    long long max_sum = LLONG_MIN;
    int i = 1;
    while (i < n - 2) {
        if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
            int j = i + 1;
            long long current_dec = nums[i];
            
            while (j < n - 1 && nums[j] > nums[j + 1]) {
                current_dec += nums[j];
                j++;
            }
            current_dec += nums[j];

            if (j < n - 1 && nums[j] < nums[j + 1]) {
                long long total = L[i - 1] + current_dec + R[j + 1];
                if (total > max_sum) {
                    max_sum = total;
                }
            }
            i = j; 
        } else {
            i++;
        }
    }

    free(L);
    free(R);
    return max_sum;
}