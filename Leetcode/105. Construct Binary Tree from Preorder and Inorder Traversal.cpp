struct TreeNode* build(int* preorder, int preStart, int preEnd, int* inorder, int inStart, int inEnd) {
    if (preStart > preEnd || inStart > inEnd) return NULL;

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[preStart];
    
    int inIndex = 0;
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == root->val) {
            inIndex = i;
            break;
        }
    }

    int leftSize = inIndex - inStart;
    root->left = build(preorder, preStart + 1, preStart + leftSize, inorder, inStart, inIndex - 1);
    root->right = build(preorder, preStart + leftSize + 1, preEnd, inorder, inIndex + 1, inEnd);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    return build(preorder, 0, preorderSize - 1, inorder, 0, inorderSize - 1);
}