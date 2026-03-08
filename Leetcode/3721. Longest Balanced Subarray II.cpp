#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Coordinate Compression Helper ---
typedef struct {
    int val;
    int original_idx;
} Element;

int compareElements(const void* a, const void* b) {
    return ((Element*)a)->val - ((Element*)b)->val;
}

// --- Segment Tree Structure ---
// We need to store min and max to quickly check if '0' exists in a range.
int* tree_min;
int* tree_max;
int* tree_lazy;
int n_size;

void push(int node) {
    if (tree_lazy[node] != 0) {
        int left = 2 * node;
        int right = 2 * node + 1;
        
        tree_lazy[left] += tree_lazy[node];
        tree_min[left] += tree_lazy[node];
        tree_max[left] += tree_lazy[node];
        
        tree_lazy[right] += tree_lazy[node];
        tree_min[right] += tree_lazy[node];
        tree_max[right] += tree_lazy[node];
        
        tree_lazy[node] = 0;
    }
}

void update(int node, int start, int end, int l, int r, int val) {
    if (l > end || r < start) return;
    
    if (l <= start && end <= r) {
        tree_lazy[node] += val;
        tree_min[node] += val;
        tree_max[node] += val;
        return;
    }
    
    push(node);
    int mid = (start + end) / 2;
    update(2 * node, start, mid, l, r, val);
    update(2 * node + 1, mid + 1, end, l, r, val);
    
    tree_min[node] = (tree_min[2 * node] < tree_min[2 * node + 1]) ? tree_min[2 * node] : tree_min[2 * node + 1];
    tree_max[node] = (tree_max[2 * node] > tree_max[2 * node + 1]) ? tree_max[2 * node] : tree_max[2 * node + 1];
}

// Find the leftmost index in [q_start, q_end] that has value 0
int queryFirstZero(int node, int start, int end, int q_start, int q_end) {
    // If range is out of bounds
    if (q_start > end || q_end < start) return -1;
    
    // Optimization: If 0 is not within the value range of this node, skip
    if (tree_min[node] > 0 || tree_max[node] < 0) return -1;
    
    // Leaf node check
    if (start == end) {
        return (tree_min[node] == 0) ? start : -1;
    }
    
    push(node);
    int mid = (start + end) / 2;
    
    // Try left child first for leftmost index
    int res = queryFirstZero(2 * node, start, mid, q_start, q_end);
    if (res != -1) return res;
    
    return queryFirstZero(2 * node + 1, mid + 1, end, q_start, q_end);
}

int longestBalanced(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    // 1. Coordinate Compression
    // We need to map values to 0..numsSize to use a simple array for 'last_pos'
    Element* sorted = (Element*)malloc(numsSize * sizeof(Element));
    for (int i = 0; i < numsSize; i++) {
        sorted[i].val = nums[i];
        sorted[i].original_idx = i;
    }
    qsort(sorted, numsSize, sizeof(Element), compareElements);
    
    // Rank array to store compressed values
    int* ranks = (int*)malloc(numsSize * sizeof(int));
    int rankCounter = 0;
    if (numsSize > 0) ranks[sorted[0].original_idx] = 0;
    
    for (int i = 1; i < numsSize; i++) {
        if (sorted[i].val != sorted[i-1].val) {
            rankCounter++;
        }
        ranks[sorted[i].original_idx] = rankCounter;
    }
    free(sorted); // Don't need sorted array anymore

    // 2. Initialize Data Structures
    int max_rank = rankCounter + 1;
    int* last_pos = (int*)malloc(max_rank * sizeof(int));
    for (int i = 0; i < max_rank; i++) last_pos[i] = -1;

    // Segment tree size: 4 * N is safe upper bound
    n_size = numsSize;
    tree_min = (int*)calloc(4 * n_size, sizeof(int));
    tree_max = (int*)calloc(4 * n_size, sizeof(int));
    tree_lazy = (int*)calloc(4 * n_size, sizeof(int));
    
    int max_len = 0;

    // 3. Iterate R
    for (int R = 0; R < numsSize; R++) {
        int val = nums[R];
        int rk = ranks[R];
        int prev = last_pos[rk];
        
        // Determine if adding even (+1) or odd (-1)
        // Note: The problem might have large integers, so val % 2 works fine.
        int change = (val % 2 == 0) ? 1 : -1;
        
        // Update range (prev + 1, R)
        update(1, 0, n_size - 1, prev + 1, R, change);
        
        // Update last position
        last_pos[rk] = R;
        
        // Query for leftmost 0 in range [0, R]
        int l_opt = queryFirstZero(1, 0, n_size - 1, 0, R);
        
        if (l_opt != -1) {
            int current_len = R - l_opt + 1;
            if (current_len > max_len) {
                max_len = current_len;
            }
        }
    }

    // Cleanup
    free(ranks);
    free(last_pos);
    free(tree_min);
    free(tree_max);
    free(tree_lazy);

    return max_len;
}