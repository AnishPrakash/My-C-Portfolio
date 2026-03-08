#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int stack[MAX], top = -1;
void push() {
    int val;
    if (top == MAX - 1) {
        printf("Overflow\n");
    } else {
        printf("Enter value: ");
        scanf("%d", &val);
        stack[++top] = val;
    }
}
void pop() {
    if (top == -1) {
        printf("Underflow\n");
    } else {
        printf("Popped: %d\n", stack[top--]);
    }
}
void display() {
    if (top == -1) {
        printf("Empty\n");
    } else {
        for (int i = top; i >= 0; i--) printf("%d ", stack[i]);
        printf("\n");
    }
}
int main() {
    int choice;
    while (1) {
        printf("1.Push 2.Pop 3.Display 4.Exit: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: exit(0);
        }
    }
    return 0;
}