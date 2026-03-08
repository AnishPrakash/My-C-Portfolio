#include <stdio.h>
int global = 0;
void mergeSort(int arr[],int left, int right){
	if(left<right){
		int mid = left + (right-left)/2;
		mergeSort(arr,left,mid);
		mergeSort(arr,mid+1,right);
	}
	else{
		global++;
		printf("Leaf %d: [%d]\n",global,arr[left]);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for (int i = 0; i<n; i++){
		scanf("%d",&arr[i]);
	}
	mergeSort(arr,0,n-1);
	return 0;
}