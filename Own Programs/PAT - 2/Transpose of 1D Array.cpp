#include <stdio.h>
#include <stdlib.h>
void transpose(int*arr,int n){
	int * ans = (int*)malloc((n*n)*sizeof(int));
	for (int i = 0; i<n; i++){
		for (int j = 0; j<n; j++){
			*(ans+(i*n)+j) = *(arr+(n*j)+i);
		}
	}
	for (int i = 0; i<n*n; i++){
		if(i>0) printf(" ");
		printf("%d",*(ans+i));
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int * arr = (int*)malloc((n*n)*sizeof(int));
	for (int i = 0; i<n*n; i++){
		scanf("%d",(arr+i));
	}
	transpose(arr,n);
	return 0;
}