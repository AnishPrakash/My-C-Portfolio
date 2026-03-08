bool isDigitorialPermutation(int n) {
    int fact[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    int pel = n; 
    int sum = 0;
    int digit_counts[10] = {0};
    int temp = n;
    while (temp > 0) {
        int r = temp % 10;
        sum += fact[r];       
        digit_counts[r]++; 
        temp /= 10;
    }
    int temp_sum = sum;
    if (temp_sum == 0) { 
        digit_counts[0]--;
    } else {
        while (temp_sum > 0) {
            int r = temp_sum % 10;
            digit_counts[r]--;
            temp_sum /= 10;
        }
    }
    for (int i = 0; i < 10; i++) {
        if (digit_counts[i] != 0) {
            return false;
        }
    }
    return true;
}