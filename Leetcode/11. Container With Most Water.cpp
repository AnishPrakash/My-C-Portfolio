int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int maxVal = 0;
    while (left < right) {
        int minHeight = height[left] < height[right] ? height[left] : height[right];
        int currentArea = minHeight * (right - left);
        if (currentArea > maxVal) {
            maxVal = currentArea;
        }
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return maxVal;
}