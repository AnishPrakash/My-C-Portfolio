#include <stdio.h>
int linear(int arr[],int n,int target){
	for (int i = 0; i<n; i++){
		if(arr[i]==target){
			return i;
		}
		else{
			continue;
		}
	}
	return -1;
}
int main(){
	int n,target;
	printf("Enter the size of the array.\n");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the data for the array.\n");
	for (int i = 0; i<n; i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter the target value.\n");
	scanf("%d",&target);
	int a = linear(arr,n,target);
	if (a!=-1){
		printf("%d is found at index %d",target,a);
	}
	else{
		printf("%d not present in the provided array.",target);
	}
	return 0;
}