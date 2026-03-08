int maxPower(char* s) {
    int maxCount = 1;
    int currentCount = 1;
    
    for (int i = 1; s[i] != '\0'; i++) {
        if (s[i] == s[i - 1]) {
            currentCount++;
        } else {
            currentCount = 1;
        }
        
        if (currentCount > maxCount) {
            maxCount = currentCount;
        }
    }
    return maxCount;
}