#include <stdio.h>
int main(){
	int n;
	printf("Enter the size of the array: \n");
	scanf("%d",&n);
	int arr[n];
	printf("Provide elements for the array: \n");
	for (int i = 0; i<n; i++){
		scanf("%d",&arr[i]);
		for (int j = 1; j<i+1; j++){
			int key = arr[j];
			int k = j-1;
			while(k>=0 && arr[k]>key){
				arr[k+1] = arr[k];
				k = k-1;
			}
			arr[k+1] = key;
		}
	}
	printf("Sorted Array \n");
	for (int i = 0; i<n; i++){
		printf("%d ",arr[i]);
	}
	return 0;
}