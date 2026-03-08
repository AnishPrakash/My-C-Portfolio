#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// --- Helper Structs for Coordinate Compression ---
typedef struct {
    int key;
    int originalIndex;
    int compressedVal;
} Pair;

static int cmpPair(const void *a, const void *b) {
    Pair *p1 = (Pair*)a;
    Pair *p2 = (Pair*)b;
    if (p1->key < p2->key) return -1;
    if (p1->key > p2->key) return 1;
    return 0;
}

static int cmpOriginal(const void *a, const void *b) {
    Pair *p1 = (Pair*)a;
    Pair *p2 = (Pair*)b;
    return p1->originalIndex - p2->originalIndex;
}

int longestBalanced(int* nums, int numsSize) {
    int n = numsSize;
    if (n == 0) return 0;

    // 1. Coordinate Compression
    // We map large values (e.g., 10^9) to small indices [0..n-1]
    // so we can use a simple boolean array to track "seen" elements.
    Pair *arr = (Pair*)malloc(sizeof(Pair) * n);
    for (int i = 0; i < n; i++) {
        arr[i].key = nums[i];
        arr[i].originalIndex = i;
    }

    // Sort by value to assign compressed IDs
    qsort(arr, n, sizeof(Pair), cmpPair);

    int m = 0;
    if (n > 0) {
        arr[0].compressedVal = 0;
        m = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i].key != arr[i - 1].key) {
                m++;
            }
            arr[i].compressedVal = m - 1;
        }
    }

    // Sort back to original order to reconstruct the array
    qsort(arr, n, sizeof(Pair), cmpOriginal);

    // Create a working array with compressed values
    int *compressedNums = (int*)malloc(sizeof(int) * n);
    for(int i=0; i<n; i++) {
        compressedNums[i] = arr[i].compressedVal;
    }

    // 2. Brute Force Subarray Check O(N^2)
    int maxLen = 0;
    
    // 'seen' array to track distinct elements in the current window
    // Size is 'm' because that is the count of unique numbers
    bool *seen = (bool*)malloc(sizeof(bool) * m); 

    for (int i = 0; i < n; i++) {
        // Reset counters for the subarray starting at i
        int distinctEven = 0;
        int distinctOdd = 0;
        
        // Clear the seen array (memset is fast)
        // Note: For very strict optimization, we could use an iteration ID array
        // to avoid memset, but for N <= 100, memset is fine.
        memset(seen, 0, sizeof(bool) * m);

        for (int j = i; j < n; j++) {
            int val = compressedNums[j];
            
            // Only count if we haven't seen this compressed value in the current window [i..j]
            if (!seen[val]) {
                seen[val] = true;
                // Check parity of the ORIGINAL number (nums[j])
                if (nums[j] % 2 == 0) {
                    distinctEven++;
                } else {
                    distinctOdd++;
                }
            }

            if (distinctEven == distinctOdd) {
                int currentLen = j - i + 1;
                if (currentLen > maxLen) {
                    maxLen = currentLen;
                }
            }
        }
    }

    // Cleanup
    free(arr);
    free(compressedNums);
    free(seen);

    return maxLen;
}