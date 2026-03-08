#include <stdio.h>
#include <stdlib.h>

double findMaxAverage(int* nums, int numsSize, int k) {
    double currentSum = 0;
    for (int i = 0; i < k; i++) {
        currentSum += nums[i];
    }
    
    double maxSum = currentSum;
    
    for (int i = k; i < numsSize; i++) {
        currentSum += nums[i] - nums[i - k];
        if (currentSum > maxSum) {
            maxSum = currentSum;
        }
    }
    
    return maxSum / k;
}