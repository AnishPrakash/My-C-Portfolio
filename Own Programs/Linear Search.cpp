#include <stdio.h>
int linearsearch(int arr[], int n, int target){
	for (int i = 0; i<n; i++){
		if (arr[i] == target)
			return i;
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
	}
	printf("Enter the target value: \n");
	scanf("%d",&target);
	int found = linearsearch(arr,n,target);
	if(found!=-1)
		printf("Elements found at index: %d",found);
	else
		printf("Element not found");
	return 0;
}