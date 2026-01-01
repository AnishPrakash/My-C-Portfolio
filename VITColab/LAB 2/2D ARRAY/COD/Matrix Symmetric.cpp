#include <stdio.h>
int main(){
	int R,C,count=0;
	scanf("%d %d",&R,&C);
	int arr[R][C];
	for (int i = 0; i<R; i++){
		for (int j = 0; j<C; j++){
			scanf("%d",&arr[i][j]);
		}
	}
	for (int i =0; i<R; i++){
		for (int j = 0; j<C; j++){
			if(arr[i][j]==arr[j][i]){
				count++;
			}
		}
	}
	if (count == R*C){
		printf("Matrix is symmetric");
	}
	else{
		printf("Matrix is not symmetric");
	}
	return 0;
}