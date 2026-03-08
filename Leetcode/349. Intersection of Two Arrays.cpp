int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int map[1001] = {0};
    int* result = (int*)malloc(1001 * sizeof(int));
    *returnSize = 0;
    
    for (int i = 0; i < nums1Size; i++) {
        map[nums1[i]] = 1;
    }
    
    for (int i = 0; i < nums2Size; i++) {
        if (map[nums2[i]] == 1) {
            result[(*returnSize)++] = nums2[i];
            map[nums2[i]] = 0;
        }
    }
    return result;
}