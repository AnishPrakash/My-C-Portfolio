int* findEvenNumbers(int* digits, int digitsSize, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 500); // Max possible even 3-digit nums is 450
    int count = 0;
    int freq[10] = {0};
    
    for(int i = 0; i < digitsSize; i++) {
        freq[digits[i]]++;
    }
    
    for (int i = 100; i < 1000; i += 2) {
        int tempFreq[10] = {0};
        int num = i;
        int valid = 1;
        
        int d1 = num % 10; num /= 10;
        int d2 = num % 10; num /= 10;
        int d3 = num % 10;
        
        tempFreq[d1]++;
        tempFreq[d2]++;
        tempFreq[d3]++;
        
        for (int j = 0; j < 10; j++) {
            if (tempFreq[j] > freq[j]) {
                valid = 0;
                break;
            }
        }
        
        if (valid) {
            result[count++] = i;
        }
    }
    
    *returnSize = count;
    return result;
}