void dfs(int** image, int r, int c, int rSize, int cSize, int color, int newColor) {
    if (r < 0 || c < 0 || r >= rSize || c >= cSize || image[r][c] != color) {
        return;
    }
    
    image[r][c] = newColor;
    
    dfs(image, r + 1, c, rSize, cSize, color, newColor);
    dfs(image, r - 1, c, rSize, cSize, color, newColor);
    dfs(image, r, c + 1, rSize, cSize, color, newColor);
    dfs(image, r, c - 1, rSize, cSize, color, newColor);
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    *returnSize = imageSize;
    *returnColumnSizes = (int*)malloc(imageSize * sizeof(int));
    for (int i = 0; i < imageSize; i++) {
        (*returnColumnSizes)[i] = imageColSize[i];
    }
    
    if (image[sr][sc] != color) {
        dfs(image, sr, sc, imageSize, imageColSize[0], image[sr][sc], color);
    }
    
    return image;
}