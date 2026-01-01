// You are using GCC
void swapByReference(int *a, int *b) {
    int temp = *a;
    *a=*b;
    *b = temp;
}