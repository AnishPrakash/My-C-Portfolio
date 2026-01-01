#include <stdio.h>
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int count = 1, majority = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] == majority) {
            count++;
        } else {
            count--;
        }
        if (count == 0) {
            majority = arr[i];
            count = 1;
        }
    }
    count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == majority) {
            count++;
        }
    }
    int result = (count > n / 2) ? majority : -1;
    printf("%d\n", result);
    return 0;
}