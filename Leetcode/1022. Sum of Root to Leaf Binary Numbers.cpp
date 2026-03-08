int calculateSum(struct TreeNode* root, int currentSum) {
    if (root == NULL) {
        return 0;
    }

    currentSum = (currentSum << 1) | root->val;

    if (root->left == NULL && root->right == NULL) {
        return currentSum;
    }

    return calculateSum(root->left, currentSum) + calculateSum(root->right, currentSum);
}

int sumRootToLeaf(struct TreeNode* root) {
    return calculateSum(root, 0);
}