#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 50
#define SIZE 100

char stack[MAX][SIZE];
int top = -1;

void push(char s[]) {
    if (top < MAX - 1)
        strcpy(stack[++top], s);
}

void pop(char s[]) {
    if (top >= 0)
        strcpy(s, stack[top--]);
}

void printStack() {
    printf("Stack: ");
    if (top == -1) {
        printf("empty");
    } else {
        for (int i = 0; i <= top; i++)
            printf("%s ", stack[i]);
    }
    printf("\n");
}

void evaluate(char expr[]) {
    char op1[SIZE], op2[SIZE], temp[SIZE];

    for (int i = 0; expr[i] != '\0'; i++) {

        if (isalnum(expr[i])) {
            temp[0] = expr[i];
            temp[1] = '\0';
            push(temp);
        }
        else {
            if (top < 1) {
                printf("Invalid expression\n");
                return;
            }

            pop(op2);
            pop(op1);

            snprintf(temp, SIZE, "(%s%c%s)", op1, expr[i], op2);
            push(temp);
        }

        printf("After %c ? ", expr[i]);
        printStack();
    }

    if (top == 0)
        printf("\nFinal Expression: %s\n", stack[top]);
    else
        printf("\nInvalid expression\n");
}

int main() {
    char postfix[SIZE];

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    evaluate(postfix);
    return 0;
}