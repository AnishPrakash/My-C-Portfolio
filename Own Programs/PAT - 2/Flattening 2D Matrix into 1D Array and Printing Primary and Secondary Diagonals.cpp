#include <stdio.h>
#include <stdlib.h>
int main(){
	int n;
	scanf("%d",&n);
	int * arr = (int*)calloc(n*n,sizeof(int));
	for (int i = 0; i<n*n; i++){
		scanf("%d",arr+i);
	}
	int * p = (int*)calloc(n,sizeof(int));
	int * s = (int*)calloc(n,sizeof(int));
	for (int i = 0; i<n; i++){
		for (int j = 0; j<n; j++){
			if(i==j){
				*(p+i) = *(arr+(i*n)+j);
			}
			if(i+j==n-1){
				*(s+i) = *(arr+(i*n)+j);
			}
		}
	}
	printf("Primary : ");
	for (int i = 0; i<n; i++){
		if(i>0)printf(" ");
		printf("%d",*(p+i));
	}
	printf("\n");
	printf("Secondary : ");
	for (int i = 0; i<n; i++){
		if(i>0) printf(" ");
		printf("%d",*(s+i));
	}
	return 0;
}