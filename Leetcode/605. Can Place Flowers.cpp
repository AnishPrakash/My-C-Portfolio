bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int t = 0;
    for (int i = 0; i<flowerbedSize; i++){
        if (flowerbed[i] == 1){
            continue;
        }
        int left = (i==0)?0:flowerbed[i-1];
        int right = (i==flowerbedSize-1)?0:flowerbed[i+1];
        if (left == 0 && right == 0){
            flowerbed[i] = 1;
            t++;
        }
    }
    if (t>=n)
        return true;
    else
        return false;
}