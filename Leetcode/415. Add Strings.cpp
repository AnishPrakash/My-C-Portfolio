char* addStrings(char* num1, char* num2) {
    int i = strlen(num1) - 1;
    int j = strlen(num2) - 1;
    int carry = 0;
    int len = (i > j ? i : j) + 2; 
    char* result = (char*)malloc(len + 1);
    int k = 0;

    while (i >= 0 || j >= 0 || carry) {
        int x = (i >= 0) ? num1[i--] - '0' : 0;
        int y = (j >= 0) ? num2[j--] - '0' : 0;
        int sum = x + y + carry;
        result[k++] = (sum % 10) + '0';
        carry = sum / 10;
    }
    
    result[k] = '\0';

    for (int l = 0, r = k - 1; l < r; l++, r--) {
        char temp = result[l];
        result[l] = result[r];
        result[r] = temp;
    }

    return result;
}