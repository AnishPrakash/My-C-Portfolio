char* reverseWords(char* s) {
    int len = strlen(s);
    int start = 0;
    
    for (int i = 0; i <= len; i++) {
        if (s[i] == ' ' || s[i] == '\0') {
            int left = start;
            int right = i - 1;
            while (left < right) {
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                left++;
                right--;
            }
            start = i + 1;
        }
    }
    return s;
}