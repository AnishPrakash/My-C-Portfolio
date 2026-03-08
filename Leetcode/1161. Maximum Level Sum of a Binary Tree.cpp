int maxLevelSum(struct TreeNode* root) {
    if (root == NULL) return 0;
    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 10005);
    int head = 0;
    int tail = 0;
    queue[tail++] = root;
    long long max_sum = LLONG_MIN; 
    int ans_level = 0;
    int curr_level = 1;
    while (head < tail) {
        int level_size = tail - head;
        long long current_level_sum = 0;
        for (int i = 0; i < level_size; i++) {
            struct TreeNode* node = queue[head++];
            current_level_sum += node->val;
            if (node->left != NULL) {
                queue[tail++] = node->left;
            }
            if (node->right != NULL) {
                queue[tail++] = node->right;
            }
        }
        if (current_level_sum > max_sum) {
            max_sum = current_level_sum;
            ans_level = curr_level;
        }
        curr_level++;
    }
    free(queue);
    return ans_level;
}