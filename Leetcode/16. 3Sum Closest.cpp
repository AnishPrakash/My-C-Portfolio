#include <stdlib.h>
#include <limits.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int closest = nums[0] + nums[1] + nums[2];
    
    for (int i = 0; i < numsSize - 2; i++) {
        int left = i + 1;
        int right = numsSize - 1;
        
        while (left < right) {
            int currentSum = nums[i] + nums[left] + nums[right];
            
            if (abs(target - currentSum) < abs(target - closest)) {
                closest = currentSum;
            }
            
            if (currentSum > target) {
                right--;
            } else if (currentSum < target) {
                left++;
            } else {
                return target;
            }
        }
    }
    return closest;
}