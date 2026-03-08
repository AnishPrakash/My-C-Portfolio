int lengthOfLongestSubstring(char * s) {
    int lastIndex[256];
    for (int i = 0; i < 256; i++) {
        lastIndex[i] = -1;
    }
    int left = 0;
    int maxLen = 0;
    int len = strlen(s);
    for (int right = 0; right < len; right++) {
        unsigned char currentChar = (unsigned char)s[right];
        if (lastIndex[currentChar] >= left) {
            left = lastIndex[currentChar] + 1;
        }
        lastIndex[currentChar] = right;
        int currentLen = right - left + 1;
        if (currentLen > maxLen) {
            maxLen = currentLen;
        }
    }
    return maxLen;
}