#include <stdio.h>
int main(){
	int T,I=0;
	scanf("%d",&T);
	while(I<T){
		int R,C;
		scanf("%d %d",&R,&C);
		int arr[R][C];
		for (int i = 0; i<R; i++){
			int product = 1;
			for (int j = 0; j<C; j++){
				scanf("%d",&arr[i][j]);
			}
			for (int k = 0; k<C;k++){
				product *= arr[i][k];
			}
			for (int l = 0; l<C; l++){
				arr[i][l] = product;
			}
			for (int m = 0; m<C; m++){
				printf("%d ",arr[i][m]);
			}
			printf("\n");
		}
		I++;
	}
}