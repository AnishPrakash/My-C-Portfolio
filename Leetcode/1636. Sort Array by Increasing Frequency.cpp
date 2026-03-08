int freqMap[201];

int cmp_1636(const void* a, const void* b) {
    int valA = *(int*)a;
    int valB = *(int*)b;
    int countA = freqMap[valA + 100];
    int countB = freqMap[valB + 100];
    
    if (countA == countB) return valB - valA;
    return countA - countB;
}

int* frequencySort(int* nums, int numsSize, int* returnSize) {
    for(int i = 0; i < 201; i++) freqMap[i] = 0;
    for(int i = 0; i < numsSize; i++) freqMap[nums[i] + 100]++;
    
    qsort(nums, numsSize, sizeof(int), cmp_1636);
    *returnSize = numsSize;
    return nums;
}