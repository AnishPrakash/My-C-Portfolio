#include <stdio.h>
#include <stdlib.h>
struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};
struct Node* root = NULL;
struct Node* createNode(int val){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if(!newNode){
		printf("Memory Allocation Failed");
		return NULL;
	}
	newNode->data = val;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
void insert(struct Node* temp, int val){
	if (root == NULL){
		root = createNode(val);
		return;
	}
	struct Node* queue[100];
	int front = 0, rear = 0;
	queue[rear++] = temp;
	while(front<rear){
		struct Node* current = queue[front++];
		if (current->left == NULL){
			current->left = createNode(val);
			break;
		}
		else{
			queue[rear++] = current->left;
		}
		if (current->right == NULL){
			current->right = createNode(val);
		}
		else{
			queue[rear++] = current->right;
		}
	}
}
void inorderTraversal(struct Node* temp){
	if (temp == NULL) return;
	inorderTraversal(temp->left);
	printf("%d ",temp->data);
	inorderTraversal(temp->right);
}
void preorderTraversal(struct Node* temp){
	if(temp == NULL) return;
	printf("%d ",temp->data);
	preorderTraversal(temp->left);
	preorderTraversal(temp->right);
}
void postorderTraversal(struct Node* temp){
	if (temp == NULL) return;
	postorderTraversal(temp->left);
	postorderTraversal(temp->right);
	printf("%d ",temp->data);
}
void deletedeepest(struct Node* temp, struct Node* dnode){
	struct Node* queue[100];
	int front = 0, rear = 0;
	queue[rear++] = temp;
	while(front<rear){
		struct Node* current = queue[front++];
		if (current==dnode){
			current = NULL;
			free(dnode);
			return;
		}
		if (current->right){
			if (current->right == dnode){
				current->right = NULL;
				free(dnode);
				return;
			}
			else{
				queue[rear++] = current->right;
			}
		}
		if (current->left){
			if (current->left == dnode){
				current->left = NULL;
				free(dnode);
				return;
			}
			else{
				queue[rear++] = current->left;
			}
		}
	}
}
void deleteNode(struct Node* temp, int val){
	if(root == NULL) return;
	if (root->left == NULL && root->right == NULL){
		if (root->data == val){
			free(root);
			root = NULL;
		}
		return;
	}
	struct Node* queue[100];
	int front = 0, rear = 0;
	queue[rear++] = temp;
	struct Node* keyNode = NULL;
	struct Node* current = NULL;
	while(front<rear){
		current = queue[front++];
		if (current->data == val){
			keyNode = current;
		}
		if (current->left){
			queue[rear++] = current->left;
		}
		if (current->right){
			queue[rear++] = current->right;
		}
	}
	if (keyNode!=NULL){
		int x = current->data;
		deletedeepest(root,current);
		keyNode->data = x;
	}
}
int main() {
    printf("Inserting nodes (10, 20, 30, 40, 50)...\n");
    insert(root, 10); // Becomes root
    insert(root, 20); // Left child of 10
    insert(root, 30); // Right child of 10
    insert(root, 40); // Left child of 20
    insert(root, 50); // Right child of 20

    /* Tree Structure:
            10
           /  \
         20    30
        /  \
      40    50
    */

    printf("\n--- Traversals ---");
    printf("\nInorder   : ");
    inorderTraversal(root);
    printf("\nPreorder  : ");
    preorderTraversal(root);
    printf("\nPostorder : ");
    postorderTraversal(root);
    printf("\n");

    printf("\n--- Deletion ---");
    printf("\nDeleting node 20...");
    deleteNode(root, 20);
    
    /* To delete 20, we find the deepest node (50), 
       copy 50 into 20's spot, and delete the leaf node 50.
       New Tree Structure:
            10
           /  \
         50    30
        /  
      40    
    */

    printf("\nInorder after deleting 20: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}