struct TreeNode* createBST(int* nums, int left, int right) {
    if (left > right) {
        return NULL;
    }
    int mid = left + (right - left) / 2;
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = nums[mid];
    node->left = createBST(nums, left, mid - 1);
    node->right = createBST(nums, mid + 1, right);
    return node;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return createBST(nums, 0, numsSize - 1);
}