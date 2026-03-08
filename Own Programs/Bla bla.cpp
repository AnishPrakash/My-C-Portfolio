#include <stdio.h>

void setZero(int *ptr) {
    *ptr = NULL;
}

int main() {
    int a = 10;
    setZero(&a);
    printf("%d", a);
    return 0;
}