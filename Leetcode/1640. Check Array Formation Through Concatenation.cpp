bool canFormArray(int* arr, int arrSize, int** pieces, int piecesSize, int* piecesColSize) {
    int i = 0;
    while (i < arrSize) {
        int found = -1;
        for (int j = 0; j < piecesSize; j++) {
            if (pieces[j][0] == arr[i]) {
                found = j;
                break;
            }
        }
        if (found == -1) return false;
        for (int j = 0; j < piecesColSize[found]; j++) {
            if (arr[i] != pieces[found][j]) return false;
            i++;
        }
    }
    return true;
}