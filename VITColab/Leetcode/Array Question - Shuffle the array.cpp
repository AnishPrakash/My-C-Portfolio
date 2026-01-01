/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    int* ans = (int*)malloc(numsSize*sizeof(int));
    int arr[numsSize/2],arr1[numsSize/2];
    for (int i = 0; i<n; i++){
        arr[i] = nums[i];
    }
    for (int i = 0; i<n; i++){
        arr1[i] = nums[n+i];
    }
    int i = 0,j = 0, k = 0;
    while (i!=numsSize){
        if (i%2 == 0){
            ans[i] = arr[k];
            i++;
            k++;
        }
        else{
            ans[i] = arr1[j];
            i++;
            j++;
        }
    }
    *returnSize = numsSize;
    return ans;
}