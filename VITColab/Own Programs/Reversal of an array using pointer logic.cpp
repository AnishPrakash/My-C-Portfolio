#include <stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void reverseArray(int *arr, int size) {
    int *ptr_left = arr;
    int *ptr_right = arr + size - 1;
    while (ptr_left < ptr_right) {
        swap(ptr_left, ptr_right);
        ptr_left++;  
        ptr_right--;
    }
}
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\nOriginal Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    reverseArray(arr, n);
    printf("\nReversed Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
    return 0;
}