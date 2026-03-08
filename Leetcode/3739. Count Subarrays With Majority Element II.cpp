#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void update(int* bit, int size, int index, int val) {
    for (; index < size; index += index & (-index)) {
        bit[index] += val;
    }
}

int query(int* bit, int index) {
    int sum = 0;
    for (; index > 0; index -= index & (-index)) {
        sum += bit[index];
    }
    return sum;
}

long long countMajoritySubarrays(int* nums, int numsSize, int target) {
    int n = numsSize;
    int limit = 2 * n + 2;
    int* bit = (int*)calloc(limit, sizeof(int));
    
    long long ans = 0;
    int prefix_sum = 0;
    int offset = n + 1;
    
    update(bit, limit, offset, 1);
    
    for (int i = 0; i < n; i++) {
        prefix_sum += (nums[i] == target) ? 1 : -1;
        ans += query(bit, prefix_sum + offset - 1);
        update(bit, limit, prefix_sum + offset, 1);
    }
    
    free(bit);
    return ans;
}