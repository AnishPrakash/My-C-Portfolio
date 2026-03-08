void inorder(struct TreeNode* root, struct TreeNode** arr, int* idx) {
    if (root == NULL) return;

    inorder(root->left, arr, idx);
    arr[(*idx)++] = root;
    inorder(root->right, arr, idx);
}

// build balanced BST from sorted nodes
struct TreeNode* buildBalanced(struct TreeNode** arr, int start, int end) {
    if (start > end) return NULL;

    int mid = start + (end - start) / 2;
    struct TreeNode* root = arr[mid];

    root->left = buildBalanced(arr, start, mid - 1);
    root->right = buildBalanced(arr, mid + 1, end);

    return root;
}

// count nodes
int countNodes(struct TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

struct TreeNode* balanceBST(struct TreeNode* root) {
    int n = countNodes(root);

    struct TreeNode** arr = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * n);
    int idx = 0;

    inorder(root, arr, &idx);

    struct TreeNode* newRoot = buildBalanced(arr, 0, n - 1);

    free(arr);
    return newRoot;
}
