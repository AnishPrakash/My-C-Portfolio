#include <stdlib.h>

int cmp888(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int* fairCandySwap(int* aliceSizes, int aliceSizesSize, int* bobSizes, int bobSizesSize, int* returnSize) {
    long sumA = 0, sumB = 0;
    for (int i = 0; i < aliceSizesSize; i++) sumA += aliceSizes[i];
    for (int i = 0; i < bobSizesSize; i++) sumB += bobSizes[i];
    
    int diff = (sumA - sumB) / 2;
    
    qsort(bobSizes, bobSizesSize, sizeof(int), cmp888);
    
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    
    for (int i = 0; i < aliceSizesSize; i++) {
        int target = aliceSizes[i] - diff;
        int l = 0, r = bobSizesSize - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (bobSizes[mid] == target) {
                result[0] = aliceSizes[i];
                result[1] = bobSizes[mid];
                return result;
            } else if (bobSizes[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }
    return result;
}