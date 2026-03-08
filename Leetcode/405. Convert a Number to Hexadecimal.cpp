char* toHex(int num) {
    if (num == 0) return "0";
    
    char* result = (char*)malloc(9 * sizeof(char));
    unsigned int n = (unsigned int)num;
    char map[] = "0123456789abcdef";
    int index = 0;
    
    while (n > 0) {
        result[index++] = map[n % 16];
        n /= 16;
    }
    result[index] = '\0';
    
    int start = 0;
    int end = index - 1;
    while (start < end) {
        char temp = result[start];
        result[start] = result[end];
        result[end] = temp;
        start++;
        end--;
    }
    
    return result;
}