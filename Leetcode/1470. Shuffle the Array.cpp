int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    int* ans = (int*)malloc(numsSize*sizeof(int));
    for (int i = 0;i<n;i++){
        ans[2*i] = nums[i];
        ans[2*i+1] = nums[n+i];
    }
    *returnSize = numsSize;
    return ans;
}