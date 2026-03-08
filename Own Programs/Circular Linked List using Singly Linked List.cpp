#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *flink;
    struct node *blink;
};

// Create node
struct node* createNode(int val) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->flink = newnode;
    newnode->blink = newnode;
    return newnode;
}

// Insert First
struct node* insertFirst(struct node* head, int val) {
    struct node* newnode = createNode(val);
    if (head == NULL) return newnode;
    
    struct node* last = head->blink;
    
    newnode->flink = head;
    newnode->blink = last;
    last->flink = newnode;
    head->blink = newnode;
    
    return newnode; 
}

// Insert Last
struct node* insertLast(struct node* head, int val) {
    struct node* newnode = createNode(val);
    if (head == NULL) return newnode;
    
    struct node* last = head->blink;
    
    newnode->flink = head;
    newnode->blink = last;
    last->flink = newnode;
    head->blink = newnode;
    
    return head; 
}

// Delete First
struct node* deleteFirst(struct node* head) {
    if (head == NULL) return NULL;
    if (head->flink == head) {
        free(head);
        return NULL;
    }
    
    struct node* last = head->blink;
    struct node* temp = head;
    
    head = head->flink;
    head->blink = last;
    last->flink = head;
    
    free(temp);
    return head;
}

// Delete Last
struct node* deleteLast(struct node* head) {
    if (head == NULL) return NULL;
    if (head->flink == head) {
        free(head);
        return NULL;
    }
    
    struct node* last = head->blink;
    struct node* newLast = last->blink;
    
    newLast->flink = head;
    head->blink = newLast;
    
    free(last);
    return head;
}

// Display
void display(struct node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node* temp = head;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->flink;
    } while (temp != head);
    printf("(HEAD)\n");
}

int main() {
    struct node* head = NULL;
    head = insertFirst(head, 200);
    head = insertFirst(head, 100);
    head = insertLast(head, 300);
    
    printf("Circular Doubly Linked List: ");
    display(head);
    
    head = deleteFirst(head);
    head = deleteLast(head);
    printf("After Deletions: ");
    display(head);
    
    return 0;
}