#include <stdio.h>
int main(){
	int R,C;
	scanf("%d %d",&R,&C);
	int m1[R][C],m2[R][C],m3[R][C];
	for (int i = 0; i<R; i++){
		for (int j = 0; j<C; j++){
			scanf("%d",&m1[i][j]);
		}
	}
	for (int i =0; i<R; i++){
		for (int k = 0; k<C; k++){
			scanf("%d",&m2[i][k]);
		}	
	}	
	for (int i = 0; i<R; i++){
		for (int j = 0; j<C; j++){
			m3[i][j] = m1[i][j]+m2[i][j];
		}
	}
	for (int i =0; i<R; i++){
		for (int j = 0; j<C;j++){
			printf("%d ",m3[i][j]);
		}
		printf("\n");
	}
	return 0;
}
