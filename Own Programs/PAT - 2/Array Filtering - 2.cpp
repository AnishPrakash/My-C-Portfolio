#include <stdio.h>
#include <stdlib.h>
int*even(int * arr, int n, int * returnSize){
	int * ans = (int*)malloc(n*sizeof(int));
	int k = 0;
	for (int i = 0; i<n; i++){
		if(*(arr+i)%2 == 0){
			ans[k] = *(arr+i);
			k++;
		}
	}
	*returnSize = k;
	return ans;
}
int main(){
	int n;
	scanf("%d",&n);
	int * arr = (int*)malloc(n*sizeof(int));
	for (int i = 0; i<n; i++){
		scanf("%d",&arr[i]);
	}
	int returnSize = 0;
	int * final = even(arr,n,&returnSize);
	for (int i = 0; i<returnSize; i++){
		if(i>0)printf(" ");
		printf("%d",*(final+i));
	}
	free(final);
	free(arr);
	return 0;
}