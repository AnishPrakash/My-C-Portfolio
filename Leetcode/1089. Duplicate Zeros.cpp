void duplicateZeros(int* arr, int arrSize) {
    int possible_dups = 0;
    int length_ = arrSize - 1;
    for (int left = 0; left <= length_ - possible_dups; left++) {
        if (arr[left] == 0) {
            if (left == length_ - possible_dups) {
                arr[arrSize - 1] = 0;
                length_ -= 1;
                break;
            }
            possible_dups++;
        }
    }
    int last = length_ - possible_dups;
    for (int i = last; i >= 0; i--) {
        if (arr[i] == 0) {
            arr[i + possible_dups] = 0;
            possible_dups--;
            arr[i + possible_dups] = 0;
        } else {
            arr[i + possible_dups] = arr[i];
        }
    }
}