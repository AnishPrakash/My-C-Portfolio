void inorderHelper(struct TreeNode* root, int* arr, int* index) {
    if (root == NULL) {
        return;
    }
    inorderHelper(root->left, arr, index);
    arr[(*index)++] = root->val;
    inorderHelper(root->right, arr, index);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;
    inorderHelper(root, result, returnSize);
    return result;
}