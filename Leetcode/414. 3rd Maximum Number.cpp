int thirdMax(int* nums, int numsSize) {
    long long int first = -999999999999999999, second = -999999999999999999, third = -999999999999999999;
    for (int i = 0; i < numsSize; i++){
        if (nums[i]==first||nums[i] == second || nums[i] == third){
            continue;
        }
        if (nums[i] > first) {
            third = second;
            second = first;
            first = nums[i];

        } 
		else if (nums[i] > second) {
            third = second;
            second = nums[i];
        }
        else if (nums[i]>third){
            third = nums[i];
        }
    }
    if (third == -999999999999999999){
        return first;
    }
    return third;
}