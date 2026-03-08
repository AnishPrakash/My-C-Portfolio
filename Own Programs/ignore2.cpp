#include <stdio.h>

int top = -1, n;

void push(int stack[]) {
    int x;
    if (top == n - 1) {
        printf("Stack overflow\n");
        return;
    }
    printf("Enter value: ");
    scanf("%d", &x);
    stack[++top] = x;
    printf("%d inserted\n", x);
}

void pop(int stack[]) {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("%d removed\n", stack[top--]);
}

void peek(int stack[]) {
    if (top == -1)
        printf("Stack is empty\n");
    else
        printf("Top element: %d\n", stack[top]);
}

void display(int stack[]) {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    int ch;

    printf("Enter stack size: ");
    scanf("%d", &n);

    int stack[n];   

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            push(stack);
            break;
        case 2:
            pop(stack);
            break;
        case 3:
            peek(stack);
            break;
        case 4:
            display(stack);
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
}