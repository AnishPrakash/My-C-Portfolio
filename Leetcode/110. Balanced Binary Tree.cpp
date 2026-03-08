int height(struct TreeNode* root) {
    if (root == NULL) return 0;

    int lh = height(root->left);
    if (lh == -1) return -1;

    int rh = height(root->right);
    if (rh == -1) return -1;

    if (lh - rh > 1 || rh - lh > 1) return -1;

    return (lh > rh ? lh : rh) + 1;
}

bool isBalanced(struct TreeNode* root) {
    return height(root) != -1;
}
