void preorderHelper(struct TreeNode* root, int* arr, int* index) {
    if (root == NULL) {
        return;
    }
    arr[(*index)++] = root->val;
    preorderHelper(root->left, arr, index);
    preorderHelper(root->right, arr, index);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(100 * sizeof(int));
    *returnSize = 0; // Initialize size to 0 
    preorderHelper(root, result, returnSize);
    return result;
}