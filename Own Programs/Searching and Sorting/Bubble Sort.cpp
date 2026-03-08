//Bubble Sort
#include <stdio.h>
void BubbleSort(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main(){
    int n;
    printf("Enter the Size of the Array: \n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the Elements of the Unsorted Array: \n");
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, n - 1); 
    printf("\nSorted Array: \n");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}