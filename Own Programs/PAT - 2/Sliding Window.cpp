#include <stdio.h>
#include <stdlib.h>
int main(){
	int n;
	scanf("%d",&n);
	int * arr = (int*)calloc(n,sizeof(int));
	for (int i = 0; i<n; i++){
		scanf("%d",arr+i);
	}
	int * arr1 = (int*)calloc(n,sizeof(int));
	int k = 0;
	for (int i = 0; i<n-2; i++){
		int avg = (*(arr+i)+*(arr+i+1)+*(arr+i+2))/3;
		*(arr1+k) = avg;
		k++;
	}
	for (int i = 0; i<k; i++){
		if(i>0) printf(" ");
		printf("%d",*(arr1+i));
	}
	return 0;
}