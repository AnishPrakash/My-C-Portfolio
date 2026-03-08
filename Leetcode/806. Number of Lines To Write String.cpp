int* numberOfLines(int* widths, int widthsSize, char* s, int* returnSize) {
    int lines = 1;
    int width = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        int w = widths[s[i] - 'a'];
        if (width + w > 100) {
            lines++;
            width = w;
        } else {
            width += w;
        }
    }
    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = lines;
    result[1] = width;
    *returnSize = 2;
    return result;
}