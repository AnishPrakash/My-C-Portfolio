int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int map[10001]; 
    int stack[1001]; 
    int top = -1; 
    for(int i = 0; i < 10001; i++) map[i] = -1;
    for (int i = 0; i < nums2Size; i++) {
        while (top > -1 && nums2[i] > stack[top]) {
            int smallerNum = stack[top--];
            map[smallerNum] = nums2[i]; 
        }
        stack[++top] = nums2[i];
    }
    int* result = (int*)malloc(nums1Size * sizeof(int));
    *returnSize = nums1Size;
    for (int i = 0; i < nums1Size; i++) {
        result[i] = map[nums1[i]];
    }
    return result;
}