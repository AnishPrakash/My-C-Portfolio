int** flipAndInvertImage(int** image, int imageSize, int* imageColSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = imageSize;
    *returnColumnSizes = (int*)malloc(imageSize * sizeof(int));
    for (int i = 0; i < imageSize; i++) {
        (*returnColumnSizes)[i] = imageColSize[i];
        int left = 0; 
        int right = imageColSize[i] - 1;
        while (left <= right) {
            int temp = image[i][left] ^ 1;
            image[i][left] = image[i][right] ^ 1;
            image[i][right] = temp;
            left++;
            right--;
        }
    }
    return image;
}