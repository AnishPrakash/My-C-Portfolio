#include <stdio.h>
int binarysearch(int arr[], int n, int target){
	int low = 0;
	int high = n;
	while(low<=high){
		int mid = low + (high-low)/2;
		if(arr[mid]==target) return mid;
		else if(arr[mid]>target)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}
int main(){
	int n,target;
	printf("Enter the size of the array: \n");
	scanf("%d",&n);
	int arr[n];
	printf("Provide the elements for the array: \n");
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
	printf("Enter the target value: \n");
	scanf("%d",&target);
	int found = binarysearch(arr,n,target);
	if(found!=-1)
		printf("Elements found at index: %d",found);
	else
		printf("Element not found");
	return 0;
}