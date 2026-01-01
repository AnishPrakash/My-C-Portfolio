#include <stdio.h>
int main(){
	int n,target;
	printf("Enter the size of the array.\n");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements for the array\n");
	for(int i = 0; i<n; i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter the target element\n");
	scanf("%d",&target);
	int found = 0;
	int index;
	for (int i = 0; i<n; i++){
		if(arr[i] == target){
			found++;
			index = i;
			break;
		}
	}
	if(found!=0){
		printf("Element found at index %d.",index);
	}
	else{
		printf("Not found.");
	}
	return 0;
}