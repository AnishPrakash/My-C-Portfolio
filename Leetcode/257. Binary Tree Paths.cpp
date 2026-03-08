void dfs(struct TreeNode* node, char* buffer, int len, char*** result, int* size, int* capacity) {
    if (!node) return;

    int written = sprintf(buffer + len, "%d", node->val);
    int newLen = len + written;

    if (!node->left && !node->right) {
        if (*size >= *capacity) {
            *capacity *= 2;
            *result = realloc(*result, sizeof(char*) * (*capacity));
        }
        (*result)[*size] = (char*)malloc(newLen + 1);
        memcpy((*result)[*size], buffer, newLen);
        (*result)[*size][newLen] = '\0';
        (*size)++;
    } else {
        buffer[newLen] = '-';
        buffer[newLen + 1] = '>';
        if (node->left) dfs(node->left, buffer, newLen + 2, result, size, capacity);
        if (node->right) dfs(node->right, buffer, newLen + 2, result, size, capacity);
    }
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    int capacity = 100;
    char** result = (char**)malloc(sizeof(char*) * capacity);
    *returnSize = 0;
    
    if (!root) return result;

    char buffer[4000]; 
    dfs(root, buffer, 0, &result, returnSize, &capacity);

    return result;
}