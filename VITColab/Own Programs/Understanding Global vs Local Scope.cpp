#include <stdio.h>
int x = 10;
void printGlobal() {
    printf("Global x: %d\n", x);
}
int main() {
    int x = 20;
    printf("Local x inside main: %d\n", x);
    printGlobal();
    {
        int x = 30;
        printf("Inner block x: %d\n", x);
    }
    return 0;
}