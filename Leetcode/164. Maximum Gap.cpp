#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maximumGap(int* nums, int numsSize) {
    if (numsSize < 2) return 0;

    int minVal = INT_MAX;
    int maxVal = INT_MIN;

    for (int i = 0; i < numsSize; i++) {
        minVal = MIN(minVal, nums[i]);
        maxVal = MAX(maxVal, nums[i]);
    }

    if (minVal == maxVal) return 0;

    int bucketSize = (int)ceil((double)(maxVal - minVal) / (numsSize - 1));
    int bucketCount = (maxVal - minVal) / bucketSize + 1;

    int* minBucket = (int*)malloc(bucketCount * sizeof(int));
    int* maxBucket = (int*)malloc(bucketCount * sizeof(int));

    for (int i = 0; i < bucketCount; i++) {
        minBucket[i] = INT_MAX;
        maxBucket[i] = INT_MIN;
    }

    for (int i = 0; i < numsSize; i++) {
        int idx = (nums[i] - minVal) / bucketSize;
        minBucket[idx] = MIN(minBucket[idx], nums[i]);
        maxBucket[idx] = MAX(maxBucket[idx], nums[i]);
    }

    int maxGap = 0;
    int prevMax = minVal;

    for (int i = 0; i < bucketCount; i++) {
        if (minBucket[i] == INT_MAX) continue;
        
        maxGap = MAX(maxGap, minBucket[i] - prevMax);
        prevMax = maxBucket[i];
    }

    free(minBucket);
    free(maxBucket);

    return maxGap;
}