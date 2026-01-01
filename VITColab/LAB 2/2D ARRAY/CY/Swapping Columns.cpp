#include <stdio.h>
int main(){
	int T,I=0;
	scanf("%d",&T);
	while(I<T){
		int r,c;
		scanf("%d %d",&r,&c);
		int arr[r][c];
		for (int i = 0; i<r; i++){
			for (int j = 0; j<c; j++){
				scanf("%d",&arr[i][j]);
			}
		}
		int s1,s2,temp = 0;
		scanf("%d %d",&s1,&s2);
		for (int i = 0; i<r;i++){
			temp = arr[i][s1];
			arr[i][s1]=arr[i][s2];
			arr[i][s2]=temp;
		}
		for (int i = 0; i<r; i++){
			for (int j = 0; j<c; j++){
				printf("%d ",arr[i][j]);
			}
			printf("\n");
		}
		I++;
	}
	return 0;
}