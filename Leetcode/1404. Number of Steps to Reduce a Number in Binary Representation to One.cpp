int numSteps(char *s) {
    int steps = 0;
    int carry = 0;
    int n = 0;
    
    while (s[n] != '\0') n++;
    
    for (int i = n - 1; i > 0; i--) {
        int bit = (s[i] - '0') + carry;
        if (bit == 1) {
            steps += 2;
            carry = 1;
        } else {
            steps += 1;
        }
    }
    
    return steps + carry;
}