#include <stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for (int i = 0; i<n; i++){
		scanf("%d",&arr[i]);
	}
	int k,min_idx1;
	scanf("%d",&k);
	for (int i = 0; i<k; i++){
		int min_idx = i;
		for (int j = i+1; j<n; j++){
			if (arr[min_idx]>arr[j]){
				min_idx = j;
				min_idx1 = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[min_idx];
		arr[min_idx] = temp;
	}
	printf("3rd Smallest: %d",arr[k-1]);
	return 0;
}