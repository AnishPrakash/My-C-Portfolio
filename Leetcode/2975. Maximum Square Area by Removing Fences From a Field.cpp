#include <stdio.h>
#include <stdlib.h>

int compareInt(const void* a, const void* b) {
    int int_a = *((int*)a);
    int int_b = *((int*)b);
    if (int_a < int_b) return -1;
    if (int_a > int_b) return 1;
    return 0;
}

int compareLong(const void* a, const void* b) {
    long long ll_a = *((long long*)a);
    long long ll_b = *((long long*)b);
    if (ll_a < ll_b) return -1;
    if (ll_a > ll_b) return 1;
    return 0;
}

long long* generateGaps(int* fences, int fencesSize, int boundary, int* returnSize) {
    int totalFences = fencesSize + 2;
    int* allFences = (int*)malloc(totalFences * sizeof(int));
    
    for (int i = 0; i < fencesSize; i++) {
        allFences[i] = fences[i];
    }
    allFences[fencesSize] = 1;
    allFences[fencesSize + 1] = boundary;
    
    qsort(allFences, totalFences, sizeof(int), compareInt);

    int maxGaps = (totalFences * (totalFences - 1)) / 2;
    long long* gaps = (long long*)malloc(maxGaps * sizeof(long long));
    int k = 0;

    for (int i = 0; i < totalFences; i++) {
        for (int j = i + 1; j < totalFences; j++) {
            gaps[k++] = (long long)allFences[j] - allFences[i];
        }
    }
    
    free(allFences);
    *returnSize = k;
    return gaps;
}

int maximizeSquareArea(int m, int n, int* hFences, int hFencesSize, int* vFences, int vFencesSize) {
    int hGapsCount, vGapsCount;
    
    long long* hGaps = generateGaps(hFences, hFencesSize, m, &hGapsCount);
    long long* vGaps = generateGaps(vFences, vFencesSize, n, &vGapsCount);
    
    qsort(hGaps, hGapsCount, sizeof(long long), compareLong);
    qsort(vGaps, vGapsCount, sizeof(long long), compareLong);
    
    long long maxGap = -1;
    int i = hGapsCount - 1;
    int j = vGapsCount - 1;
    
    while (i >= 0 && j >= 0) {
        if (hGaps[i] == vGaps[j]) {
            maxGap = hGaps[i];
            break;
        } else if (hGaps[i] > vGaps[j]) {
            i--;
        } else {
            j--;
        }
    }
    
    free(hGaps);
    free(vGaps);
    
    if (maxGap == -1) {
        return -1;
    }
    
    long long modulo = 1000000007;
    return (int)((maxGap * maxGap) % modulo);
}