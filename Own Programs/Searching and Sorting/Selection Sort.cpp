//Selection Sort
#include <stdio.h>
void SelectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}
int main(){
	int n;
	printf("Enter the Size of the Array: \n");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the Elements of the Unsorted Array: \n");
	for (int i = 0; i<n; i++){
		scanf("%d",&arr[i]);
	}
	SelectionSort(arr,n);
	for (int i = 0; i<n; i++){
		printf("%d ",arr[i]);
	}
	return 0;
}