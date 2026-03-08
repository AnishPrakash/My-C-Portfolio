#include <stdio.h> 	
#include <stdlib.h>
struct node {
    int data;
    struct node *link;
};
struct node* createNode(int val) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node)); 
    newnode->data = val; 
    newnode->link = NULL;
    return newnode;
}
struct node* insertFirst(struct node* head, int val) {
    struct node* newnode = createNode(val);
    newnode->link = head; 
    return newnode; 
}
struct node* insertLast(struct node* head, int val) {
    struct node* newnode = createNode(val);
    if (head == NULL) return newnode;
    struct node* temp = head;
    while (temp->link != NULL) temp = temp->link; 
    temp->link = newnode; 
    return head;
}
struct node* insertMiddle(struct node* head, int val, int x) {
    struct node* temp = head;
    while (temp != NULL) {
        if (temp->data == x) { 
            struct node* newnode = createNode(val);
            newnode->link = temp->link; 
            temp->link = newnode;
            return head;
        }
        temp = temp->link;
    }
    printf("Value %d not found.\n", x);
    return head;
}
struct node* deleteFirst(struct node* head) {
    if (head == NULL) return NULL; 
    struct node* delnode = head; 
    head = head->link; 
    free(delnode); 
    return head;
}
struct node* deleteLast(struct node* head) {
    if (head == NULL || head->link == NULL) return deleteFirst(head); 
    struct node* temp = head;
    struct node* prev = NULL;
    while (temp->link != NULL) {
        prev = temp; 
        temp = temp->link; 
    }
    prev->link = NULL;
    free(temp); 
    return head;
}
void display(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) { 
        printf("%d -> ", temp->data);
        temp = temp->link; 
    }
    printf("NULL\n");
}
int main() {
    struct node* head = NULL;
    head = insertFirst(head, 10);
    head = insertLast(head, 20);
    head = insertMiddle(head, 15, 10);
    display(head);
    head = deleteFirst(head);
    display(head);
    return 0;
}
