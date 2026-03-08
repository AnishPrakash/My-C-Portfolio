int* toggleLightBulbs(int* bulbs, int bulbsSize, int* returnSize) {
    int seen[101] = {0};
    for (int i = 0; i<bulbsSize; i++){
        if(seen[bulbs[i]] == 0)
            seen[bulbs[i]] = 1;
        else
            seen[bulbs[i]] = 0;
    }
    int count = 0;
    for (int i = 0; i<101; i++){
        if(seen[i] == 1){
            count++;
        }
    }
    *returnSize = count;
    int * ans = (int*)malloc(count*sizeof(int));
    int j = 0;
    for (int i = 0; i<101; i++){
        if(seen[i] == 1){
            ans[j] = i;
            j++;
        }
    }
    return ans;
}