#include <stdlib.h>
#include <string.h>

long long* tree_val;
int* tree_cnt;
int max_rank;

void update(int idx, int cnt_delta, long long val_delta) {
    for (; idx <= max_rank; idx += idx & -idx) {
        tree_cnt[idx] += cnt_delta;
        tree_val[idx] += val_delta;
    }
}

int query_kth_rank(int k) {
    int idx = 0;
    int current_cnt = 0;
    for (int i = 1 << 17; i > 0; i >>= 1) {
        if (idx + i <= max_rank && tree_cnt[idx + i] + current_cnt < k) {
            idx += i;
            current_cnt += tree_cnt[idx];
        }
    }
    return idx + 1;
}

long long query_sum(int idx) {
    long long sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum += tree_val[idx];
    }
    return sum;
}

int query_cnt_func(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum += tree_cnt[idx];
    }
    return sum;
}

int compare(const void* a, const void* b) {
    int val_a = *(int*)a;
    int val_b = *(int*)b;
    if (val_a < val_b) return -1;
    if (val_a > val_b) return 1;
    return 0;
}

int get_rank(int* sorted, int n, int val) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (sorted[mid] == val) return mid + 1;
        if (sorted[mid] < val) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

long long minimumCost(int* nums, int numsSize, int k, int dist) {
    int n = numsSize;
    int* sorted = (int*)malloc((n - 1) * sizeof(int));
    for (int i = 1; i < n; i++) {
        sorted[i - 1] = nums[i];
    }
    
    qsort(sorted, n - 1, sizeof(int), compare);
    
    int m = 0;
    for (int i = 0; i < n - 1; i++) {
        if (i == 0 || sorted[i] != sorted[i - 1]) {
            sorted[m++] = sorted[i];
        }
    }
    
    max_rank = m;
    tree_val = (long long*)calloc(m + 1, sizeof(long long));
    tree_cnt = (int*)calloc(m + 1, sizeof(int));
    
    int needed = k - 1;
    long long min_sum = -1;
    
    for (int i = 1; i < n; i++) {
        int r = get_rank(sorted, m, nums[i]);
        update(r, 1, nums[i]);
        
        if (i > dist + 1) {
            int remove_r = get_rank(sorted, m, nums[i - dist - 1]);
            update(remove_r, -1, -nums[i - dist - 1]);
        }
        
        if (i >= needed) { 
            int current_window_size = (i < dist + 1) ? i : dist + 1;
            if (current_window_size >= needed) {
                int rank_limit = query_kth_rank(needed);
                long long current_sum = query_sum(rank_limit);
                int count_at_limit = query_cnt_func(rank_limit);
                
                if (count_at_limit > needed) {
                    current_sum -= (long long)(count_at_limit - needed) * sorted[rank_limit - 1];
                }
                
                if (min_sum == -1 || current_sum < min_sum) {
                    min_sum = current_sum;
                }
            }
        }
    }
    
    free(sorted);
    free(tree_val);
    free(tree_cnt);
    
    return nums[0] + min_sum;
}