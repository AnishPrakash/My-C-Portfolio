#include <stdio.h>
int BinarySearch(int arr[], int target, int size) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } 
		else {
            right = mid - 1;
        }
    }
    return -1;
}
int main() {
    int n, target;
    printf("Enter the Size of the Array: \n");
    scanf("%d", &n);
    printf("Enter the Target Value: \n");
    scanf("%d", &target);
    printf("Enter the Elements for the Array: \n");
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int found = BinarySearch(arr, target, n);
    if (found != -1)
        printf("\nTarget Element %d found at index %d.\n", target, found);
    else
        printf("\nTarget Element %d not found in the provided Array.\n", target);
    return 0;
}