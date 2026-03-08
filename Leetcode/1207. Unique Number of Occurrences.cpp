bool uniqueOccurrences(int* arr, int arrSize) {
    int arr1[2001] = {0};
    for (int i = 0; i<arrSize; i++){
        arr1[arr[i]+1000]++;
    }
    bool seenFreq[1001] = {false};
    for (int i = 0; i<2001; i++){
        int count = arr1[i];
        if(count == 0){
            continue;
        }
        if(seenFreq[count] == true){
            return false;
        }
        seenFreq[count] = true;
    }
    return true;
}