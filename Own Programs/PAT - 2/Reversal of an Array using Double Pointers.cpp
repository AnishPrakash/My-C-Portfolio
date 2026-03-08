#include <stdio.h>
void reverseArray(int * arr, int n){
	int * left = arr;
	int * right = arr + n - 1;
	while(left<right){
		int temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for (int i = 0; i<n; i++){
		scanf("%d",&arr[i]);
	}
	reverseArray(arr,n);
	for (int i = 0; i<n; i++){
		if(i>0)printf(" ");
		printf("%d",arr[i]);
	}
	return 0;
}