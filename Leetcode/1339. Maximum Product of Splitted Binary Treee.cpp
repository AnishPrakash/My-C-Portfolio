long long totalSum = 0;
long long maxProd = 0;
long long dfs(struct TreeNode* root, int checkMax) {
    if (root == NULL) {
        return 0;
    }
    long long leftSum = dfs(root->left, checkMax);
    long long rightSum = dfs(root->right, checkMax);
    long long currentSum = leftSum + rightSum + root->val;
    if (checkMax) {
        long long currentProduct = currentSum * (totalSum - currentSum);
        if (currentProduct > maxProd) {
            maxProd = currentProduct;
        }
    }
    return currentSum;
}
int maxProduct(struct TreeNode* root) {
    totalSum = 0;
    maxProd = 0;
    totalSum = dfs(root, 0);
    dfs(root, 1);
    return (int)(maxProd % 1000000007);
}