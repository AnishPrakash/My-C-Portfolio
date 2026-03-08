int findShortestSubArray(int* nums, int numsSize) {
    int count[50000] = {0};
    int first[50000]; 
    int last[50000];
    for(int i = 0; i < 50000; i++) {
        first[i] = -1;
    }
    int degree = 0;
    int maxVal = 0; 
    for (int i = 0; i < numsSize; i++) {
        int val = nums[i];
        if (val > maxVal) maxVal = val;
        if (first[val] == -1) {
            first[val] = i;
        }
        last[val] = i;
        count[val]++;

        if (count[val] > degree) {
            degree = count[val];
        }
    }
    int minLen = numsSize;
    for (int i = 0; i <= maxVal; i++) {
        if (count[i] == degree) {
            int currentLen = last[i] - first[i] + 1;
            if (currentLen < minLen) {
                minLen = currentLen;
            }
        }
    }
    return minLen;
}