bool isValidSerialization(char * preorder) {
    int slots = 1;
    int n = strlen(preorder);

    for (int i = 0; i < n; i++) {
        if (preorder[i] == ',') continue;

        if (--slots < 0) return false;

        if (preorder[i] != '#') {
            slots += 2;
            while (i < n && preorder[i] != ',' && preorder[i] != '#') {
                i++;
            }
        }
    }

    return slots == 0;
}