int sumFourDivisors(int* nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i<numsSize; i++){
        int k = 0;
        int temp = 0;
        for (int j = 1; j*j<=nums[i]; j++){
            if (nums[i]%j == 0){
                if (j*j == nums[i]){
                    k++;
                    temp += j;
                }
                else{
                    k+=2;
                    temp += (j+nums[i]/j);
                }
                if (k>4){
                    break;
                }
            }
        }
        if (k == 4){
            sum += temp;
        }
    }
    return sum;
}