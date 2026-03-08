int maxDistance(int* colors, int colorsSize) {
    int n = colorsSize, i = 0, j = n - 1;
    while (colors[0] == colors[j]) j--;
    while (colors[n - 1] == colors[i]) i++;
    return (j > (n - 1 - i)) ? j : (n - 1 - i);
}