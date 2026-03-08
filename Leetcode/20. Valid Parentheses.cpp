bool isValid(char * s) {
    int n = strlen(s);
    if (n % 2 != 0) 
        return false;
    char *stack = (char *)malloc(n * sizeof(char));
    int top = -1;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        } 
        else {
            if (top == -1) {
                free(stack);
                return false;
            }
            char open = stack[top--];
            if (c == ')' && open != '('){ 
                return false; 
            }
            if (c == '}' && open != '{'){ 
                return false; 
            }
            if (c == ']' && open != '['){
                return false;
            }
        }
    }
    bool result = (top == -1);
    return result;
}