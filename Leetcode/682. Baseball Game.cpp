int calPoints(char** operations, int operationsSize) {
    int* stack = (int*)malloc(operationsSize * sizeof(int));
    int top = -1;
    
    for (int i = 0; i < operationsSize; i++) {
        if (strcmp(operations[i], "+") == 0) {
            int val1 = stack[top];
            int val2 = stack[top - 1];
            stack[++top] = val1 + val2;
        } else if (strcmp(operations[i], "D") == 0) {
            stack[++top] = 2 * stack[top];
        } else if (strcmp(operations[i], "C") == 0) {
            top--;
        } else {
            stack[++top] = atoi(operations[i]);
        }
    }
    
    int sum = 0;
    for (int i = 0; i <= top; i++) {
        sum += stack[i];
    }
    
    free(stack);
    return sum;
}