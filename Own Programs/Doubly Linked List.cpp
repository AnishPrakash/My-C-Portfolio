#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *flink;
    struct node *blink;
};
struct node* createNode(int val) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node)); 
    newnode->data = val; 
    newnode->flink = newnode->blink = NULL;
    return newnode;
}
struct node* insertFirst(struct node* head, int val) {
    struct node* newnode = createNode(val);
    if (head != NULL) {
        newnode->flink = head; 
        head->blink = newnode; 
    }
    return newnode; 
}
struct node* insertLast(struct node* head, int val) {
    struct node* newnode = createNode(val);
    if (head == NULL) return newnode;
    struct node* temp = head;
    while (temp->flink != NULL) temp = temp->flink;
    temp->flink = newnode; 
    newnode->blink = temp; 
    return head;
}
struct node* deleteMiddle(struct node* head, int x) {
    struct node* temp = head;
    while (temp != NULL) {
        if (temp->data == x) { 
            if (temp->blink) temp->blink->flink = temp->flink; 
            if (temp->flink) temp->flink->blink = temp->blink; 
            if (temp == head) head = temp->flink;
            free(temp); 
            return head;
        }
        temp = temp->flink;
    }
    return head;
}
void display(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) { 
        printf("%d <-> ", temp->data); 
        temp = temp->flink; 
    }
    printf("NULL\n");
}


int main() { 
struct node* head = NULL; 
head = insertFirst(head, 50); 
head = insertLast(head, 100); 
head = insertLast(head, 150);
 printf("DLL Forward Traversal: ");
 display(head); 
head = deleteMiddle(head, 100);
 printf("DLL after deleting middle element 100: ");
 display(head); 
return 0;
 }
