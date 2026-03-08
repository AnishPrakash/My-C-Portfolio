char* addStrings(char* num1, char* num2) {
    int i = strlen(num1) - 1;
    int j = strlen(num2) - 1;
    int carry = 0;
    int len = (i > j ? i : j) + 2;
    char* res = (char*)malloc((len + 1) * sizeof(char));
    int k = 0;
    
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        res[k++] = (sum % 10) + '0';
        carry = sum / 10;
    }
    res[k] = '\0';
    
    for (int l = 0; l < k / 2; l++) {
        char temp = res[l];
        res[l] = res[k - 1 - l];
        res[k - 1 - l] = temp;
    }
    return res;
}

bool isValid(char* num, long long n1_len, long long n2_len) {
    if (n1_len > 1 && num[0] == '0') return false;
    if (n2_len > 1 && num[n1_len] == '0') return false;
    
    int n = strlen(num);
    int start = n1_len + n2_len;
    
    char* s1 = (char*)malloc((n1_len + 1) * sizeof(char));
    char* s2 = (char*)malloc((n2_len + 1) * sizeof(char));
    strncpy(s1, num, n1_len); s1[n1_len] = '\0';
    strncpy(s2, num + n1_len, n2_len); s2[n2_len] = '\0';
    
    while (start < n) {
        char* sum = addStrings(s1, s2);
        int sum_len = strlen(sum);
        
        if (start + sum_len > n || strncmp(num + start, sum, sum_len) != 0) {
            free(s1); free(s2); free(sum);
            return false;
        }
        
        free(s1);
        s1 = s2;
        s2 = sum;
        start += sum_len;
    }
    
    free(s1); free(s2);
    return true;
}

bool isAdditiveNumber(char* num) {
    int n = strlen(num);
    for (int i = 1; i <= n / 2; i++) {
        for (int j = 1; n - i - j >= (i > j ? i : j); j++) {
            if (isValid(num, i, j)) return true;
        }
    }
    return false;
}