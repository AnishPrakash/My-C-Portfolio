#include <stdio.h>
void merge(int arr[], int left, int mid, int right){
	int nl = mid-left+1;
	int nr = right-mid;
	int i,j,k;
	int L[nl], R[nr];
	for (i = 0; i<nl; i++) L[i] = arr[left+i];
	for (i = 0; i<nr; i++) R[i] = arr[mid+1+i];
	i = 0; j = 0; k= left;
	while(i<nl&&j<nr){
		if(L[i]<=R[j]){
			arr[k] = L[i];
			i++;
		}
		else{
			arr[k] = R[j];
			j++;
		}
		k++;		
	}
	while (i<nl) arr[k++] = L[i++];
	while (j<nr) arr[k++] = R[j++];
}
void mergeSort(int arr[], int left, int right){
	if (left<right){
		int mid = left+(right-left)/2;
		mergeSort(arr,left,mid);
		mergeSort(arr,mid+1,right);
		merge(arr,left,mid,right);
	}
}
int main(){
	int n;
	printf("Provide the size of the array: \n");
	scanf("%d",&n);
	int arr[n];
	printf("Provide elements for the array: \n");
	for (int i = 0; i<n; i++){
		scanf("%d",&arr[i]);
	}
	mergeSort(arr,0,n-1);
	printf("Sorted Array: \n");
	for (int i = 0; i<n; i++){
		printf("%d ",arr[i]);
	}
	return 0;
}