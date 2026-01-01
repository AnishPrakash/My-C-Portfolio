#include <stdio.h>
int summation(int num);
int main() {
    int a, b, r;
    scanf("%d %d", &a, &b);
    r = b - a + 1;
    for (int i = 1; i <= r; i++) {
        int current_num = a + i - 1;
        if (i % 3 == 0) {
            int k = summation(current_num);
            printf("%d ", k);
        } else{
            printf("%d ", current_num);
        }
    }
    return 0;
}
int summation(int sum) {
    int r = 0;
    while (sum != 0) {
        r += sum % 10;
        sum /= 10;
    }
    return r;
}