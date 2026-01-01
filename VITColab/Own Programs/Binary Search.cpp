#include <stdio.h>
int main() {
    int arr[100], n, i, target, left, right, mid;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d sorted integers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter value to find: ");
    scanf("%d", &target);
    left = 0;
    right = n - 1;
    mid = (left + right) / 2;
    while (left <= right) {
        if (arr[mid] < target) {
            left = mid + 1;
        } else if (arr[mid] == target) {
            printf("%d found at location %d.\n", target, mid + 1);
            break;
        } else {
            right = mid - 1;
        }
        mid = (left + right) / 2;
    }
    if (left > right) {
        printf("Not found! %d is not present in the list.\n", target);
    }
    return 0;
}