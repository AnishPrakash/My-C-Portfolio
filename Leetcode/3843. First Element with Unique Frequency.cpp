int firstUniqueFreq(int* nums, int numsSize){
    int freq[100001] = {0};
    for (int i = 0; i < numsSize; i++){
        freq[nums[i]]++;
    }
    int* ans = nums;
    int freqCount[100001] = {0};
    for (int i = 0; i <= 100000; i++){
        if(freq[i] > 0){
            freqCount[freq[i]]++;
        }
    }
    for (int i = 0; i < numsSize; i++){
        int currentFreq = freq[ans[i]];
        if(freqCount[currentFreq] == 1){
            return ans[i];
        }
    }
    return -1;
}