int* constructRectangle(int area, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    for (int w = sqrt(area); w >= 1; w--) {
        if (area % w == 0) {
            result[0] = area / w;
            result[1] = w;
            break;
        }
    }
    return result;
}
