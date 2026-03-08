typedef struct {
    int val;
    int index;
} Element;

int cmpValDesc(const void* a, const void* b) {
    return ((Element*)b)->val - ((Element*)a)->val;
}

int cmpIndexAsc(const void* a, const void* b) {
    return ((Element*)a)->index - ((Element*)b)->index;
}

int* maxSubsequence(int* nums, int numsSize, int k, int* returnSize) {
    Element* arr = (Element*)malloc(numsSize * sizeof(Element));
    for (int i = 0; i < numsSize; i++) {
        arr[i].val = nums[i];
        arr[i].index = i;
    }
    
    qsort(arr, numsSize, sizeof(Element), cmpValDesc);
    
    qsort(arr, k, sizeof(Element), cmpIndexAsc);
    
    int* result = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        result[i] = arr[i].val;
    }
    
    free(arr);
    *returnSize = k;
    return result;
}