#include <stdio.h>
#include <stdlib.h>
struct Node{
	int data;
	struct Node * link;
};
struct Node* top = NULL;
void push(int d){
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	if(!newNode){
		printf("Heap Overflow");
		return;
	}
	newNode->data = d;
	newNode->link = top;
	top = newNode;
}
void pop(){
	if(top == NULL){
		printf("Stack Underflow");
		return;
	}
	struct Node* temp = top;
	printf("%d",temp->data);
	top = temp->link;
	free(temp);
}
void peek(){
	if(top == NULL){
		printf("Stack Underflow");
		return;
	}
	printf("%d",top->data);
}
void display(){
	if (top == NULL){
		printf("Stack Underflow");
		return;
	}
	struct Node* temp = top;
	while(temp != NULL){
		printf("%d -> ",temp->data);
		temp=temp->link;
	}
	printf("NULL");
}