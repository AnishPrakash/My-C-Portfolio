int sumOfUnique(int* nums, int numsSize) {
    int count[101] = {0};
    int sum = 0;
    for(int i = 0; i < numsSize; i++) {
        count[nums[i]]++;
    }
    for(int i = 0; i < numsSize; i++) {
        if(count[nums[i]] == 1) {
            sum += nums[i];
        }
    }
    return sum;
}