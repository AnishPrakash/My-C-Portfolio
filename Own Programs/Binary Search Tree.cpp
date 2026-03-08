#include <stdio.h>
#include <stdlib.h>
struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};
struct Node* root = NULL;
void insert(int val){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if(!newNode){
		printf("Memory Allocation Failed.\n");
		return;
	}
	newNode->data = val;
	newNode->left = NULL;
	newNode->right = NULL;
	if (root == NULL){
		root = newNode;
		return;
	}
	struct Node* current = root;
	struct Node* parent = NULL;
	while(current!=NULL){
		parent = current;
		if (val<current->data){
			current = current->left;
		}
		else if (val>current->data){
			current = current->right;
		}
		else {
			free(newNode);
			return;
		}
	}
	if (data<parent->data){
		parent->left = newNode;
	}
	else{
		parent->right = newNode;
	}
}
void inorderTraversal(struct Node* node){
	if (node == NULL) return;
	inorderTraversal(node->left);
	printf("%d ", node->data);
	inorderTraversal(node->right);
}
void preorderTraversal(struct Node* node){
	if (node == NULL) return;
	printf("%d ", node->data);
	preorderTraversal(node->left);
	preorderTraversal(node->right);
}
void postorderTraversal(struct Node* node){
	if (node == NULL) return;
	postorderTraversal(node->left);
	postorderTraversal(node->right);
	printf("%d ", node->data);
}
void deleteNode(int data){
	struct Node* current = root;
	struct Node* parent = NULL;
	while(current!= NULL && current->data!=data){
		parent = current;
		if (data<current->data){
			current = current->left;
		}
		else{
			current = current->right;
		}
	}
	if (current == NULL) return;
	if (current->left == NULL || current->right == NULL){
		struct Node* child;
		if (current->left == NULL){
			child = current->right;
		}
		else{
			child = current->left;
		}
		if (parent == NULL){
			root = child;
		}
		else if (current==parent->left){
			parent->left = child;
		}
		else{
			parent->right = child;
		}
		free(current);
	}
	else{
		struct Node* successorParent = current;
		struct Node* successor = current->right;
		while(successor->left!=NULL){
			successorParent = successor;
			successor = successor->left;
		}
		current->data = successor->data;
		if (successorParent!=current){
			successorParent -> left = successor->right;
		}
		else{
			successorParent->right = successor->right;
		}
		free(successor);
	}
}
