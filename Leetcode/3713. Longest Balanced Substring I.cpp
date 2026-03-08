int longestBalanced(char* s) {
    int n = strlen(s);
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        int freq[26] = {0}; 
        int maxFreq = 0;   
        int distinctCount = 0;
        for (int j = i; j < n; j++) {
            int idx = s[j] - 'a';
            if (freq[idx] == 0) {
                distinctCount++;
            }
            freq[idx]++;
            if (freq[idx] > maxFreq) {
                maxFreq = freq[idx];
            }
            int currentLen = j - i + 1;
            if (maxFreq * distinctCount == currentLen) {
                if (currentLen > maxLen) {
                    maxLen = currentLen;
                }
            }
        }
    }

    return maxLen;
}