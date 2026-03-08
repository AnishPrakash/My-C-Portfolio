#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int queue[MAX], front = -1, rear = -1;
void enqueue() {
    int val;
    if (rear == MAX - 1) {
        printf("Full\n");
    } else {
        printf("Enter value: ");
        scanf("%d", &val);
        if (front == -1) front = 0;
        queue[++rear] = val;
    }
}
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Empty\n");
    } else {
        printf("Dequeued: %d\n", queue[front++]);
    }
}
void display() {
    if (front == -1 || front > rear) {
        printf("Empty\n");
    } else {
        for (int i = front; i <= rear; i++) printf("%d ", queue[i]);
        printf("\n");
    }
}
int main() {
    int choice;
    while (1) {
        printf("1.Enqueue 2.Dequeue 3.Display 4.Exit: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: exit(0);
        }
    }
    return 0;
}