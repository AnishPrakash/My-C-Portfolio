char* map[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void dfs(char** res, int* size, char* digits, int idx, char* cur) {
    if (digits[idx] == '\0') {
        res[*size] = strdup(cur);
        (*size)++;
        return;
    }

    char* letters = map[digits[idx] - '0'];
    for (int i = 0; letters[i]; i++) {
        cur[idx] = letters[i];
        dfs(res, size, digits, idx + 1, cur);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    if (strlen(digits) == 0) {
        *returnSize = 0;
        return NULL;
    }

    char** res = (char**)malloc(10000 * sizeof(char*));
    char* cur = (char*)malloc(strlen(digits) + 1);
    cur[strlen(digits)] = '\0';
    *returnSize = 0;

    dfs(res, returnSize, digits, 0, cur);
    return res;
}
