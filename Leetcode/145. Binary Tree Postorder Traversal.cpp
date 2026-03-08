void postorderHelper(struct TreeNode* root, int* arr, int* index) {
    if (root == NULL) {
        return;
    }
    postorderHelper(root->left, arr, index);
    postorderHelper(root->right, arr, index);
    arr[(*index)++] = root->val;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;
    postorderHelper(root, result, returnSize);
    return result;
}