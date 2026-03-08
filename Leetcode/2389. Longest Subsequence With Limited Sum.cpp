#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* answerQueries(int* nums, int numsSize, int* queries, int queriesSize, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), cmp);

    for(int i = 1; i < numsSize; i++)
        nums[i] += nums[i - 1];

    int* ans = (int*)malloc(sizeof(int) * queriesSize);
    *returnSize = queriesSize;

    for(int i = 0; i < queriesSize; i++) {
        int left = 0, right = numsSize - 1, best = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] <= queries[i]) {
                best = mid;
                left = mid + 1;
            } else right = mid - 1;
        }
        ans[i] = best + 1;
    }
    return ans;
}
