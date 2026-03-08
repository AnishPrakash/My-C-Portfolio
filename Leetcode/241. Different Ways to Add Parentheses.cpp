int* diffWaysToCompute(char* expression, int* returnSize) {
    int len = strlen(expression);
    int capacity = 5000; 
    int* results = (int*)malloc(capacity * sizeof(int));
    int count = 0;
    
    int isNumber = 1;
    for (int i = 0; i < len; i++) {
        if (!isdigit(expression[i])) {
            isNumber = 0;
            
            char* leftPart = (char*)malloc((i + 1) * sizeof(char));
            strncpy(leftPart, expression, i);
            leftPart[i] = '\0';
            
            char* rightPart = (char*)malloc((len - i) * sizeof(char));
            strcpy(rightPart, expression + i + 1);
            
            int leftSize, rightSize;
            int* leftRes = diffWaysToCompute(leftPart, &leftSize);
            int* rightRes = diffWaysToCompute(rightPart, &rightSize);
            
            for (int l = 0; l < leftSize; l++) {
                for (int r = 0; r < rightSize; r++) {
                    if (count >= capacity) {
                        capacity *= 2;
                        results = (int*)realloc(results, capacity * sizeof(int));
                    }
                    
                    if (expression[i] == '+') {
                        results[count++] = leftRes[l] + rightRes[r];
                    } else if (expression[i] == '-') {
                        results[count++] = leftRes[l] - rightRes[r];
                    } else if (expression[i] == '*') {
                        results[count++] = leftRes[l] * rightRes[r];
                    }
                }
            }
            
            free(leftPart);
            free(rightPart);
            free(leftRes);
            free(rightRes);
        }
    }
    
    if (isNumber) {
        results[count++] = atoi(expression);
    }
    
    *returnSize = count;
    return results;
}