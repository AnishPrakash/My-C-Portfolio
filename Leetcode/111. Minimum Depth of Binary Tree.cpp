int minDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    struct TreeNode** queue = (struct TreeNode**)malloc(100000 * sizeof(struct TreeNode*));
    int front = 0;
    int rear = 0;
    queue[rear++] = root;
    int depth = 1;
    while (front < rear) {
        int levelSize = rear - front;
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* current = queue[front++];
            if (current->left == NULL && current->right == NULL) {
                free(queue);
                return depth;
            }
            if (current->left != NULL) {
                queue[rear++] = current->left;
            }
            if (current->right != NULL) {
                queue[rear++] = current->right;
            }
        }
        depth++;
    }
    free(queue);
    return depth;
}