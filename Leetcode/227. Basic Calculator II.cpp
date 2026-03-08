int calculate(char* s) {
    int len = strlen(s);
    if (len == 0) return 0;
    int* stack = (int*)malloc(len * sizeof(int));
    int top = -1;
    long currentNumber = 0;
    char lastOperator = '+';
    for (int i = 0; i < len; i++) {
        char currentChar = s[i];
        if (isdigit(currentChar)) {
            currentNumber = currentNumber * 10 + (currentChar - '0');
        }
        if ((!isdigit(currentChar) && !isspace(currentChar)) || i == len - 1) {
            if (lastOperator == '+') {
                stack[++top] = (int)currentNumber;
            } else if (lastOperator == '-') {
                stack[++top] = -(int)currentNumber;
            } else if (lastOperator == '*') {
                stack[top] = stack[top] * (int)currentNumber;
            } else if (lastOperator == '/') {
                stack[top] = stack[top] / (int)currentNumber;
            }
            lastOperator = currentChar;
            currentNumber = 0;
        }
    }
    int result = 0;
    while (top >= 0) {
        result += stack[top--];
    }
    free(stack);
    return result;
}