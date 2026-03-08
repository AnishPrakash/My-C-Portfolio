int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** minimumAbsDifference(int* arr, int n, int* returnSize, int** returnColSize) {
    qsort(arr, n, sizeof(int), cmp);
    
    int minDiff = INT_MAX;
    for(int i=1;i<n;i++)
        if(arr[i]-arr[i-1] < minDiff)
            minDiff = arr[i]-arr[i-1];
    
    int count = 0;
    for(int i=1;i<n;i++)
        if(arr[i]-arr[i-1] == minDiff)
            count++;
    
    int** res = (int**)malloc(count * sizeof(int*));
    *returnColSize = (int*)malloc(count * sizeof(int));
    
    int idx=0;
    for(int i=1;i<n;i++){
        if(arr[i]-arr[i-1] == minDiff){
            res[idx] = (int*)malloc(2*sizeof(int));
            res[idx][0] = arr[i-1];
            res[idx][1] = arr[i];
            (*returnColSize)[idx++] = 2;
        }
    }
    *returnSize = count;
    return res;
}
