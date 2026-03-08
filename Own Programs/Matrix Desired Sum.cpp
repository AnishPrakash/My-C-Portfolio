#include <stdio.h>
#include <stdlib.h>
int main(){
	int N;
	scanf("%d",&N);
	int **matrix = (int**)malloc(N*sizeof(int*));
	for(int i = 0; i<N; i++){
		matrix[i] = (int*)malloc(N*sizeof(int));
		for(int j = 0; j<N; j++){
			scanf("%d",&matrix[i][j]);
		}
	}
	int desired;
	int count = 0;
	scanf("%d",&desired);
	for(int i = 0; i<N-1; i++){
		for(int j = 0; j<N-1; j++){
			if(matrix[i][j] + matrix[i][j+1] == desired){
				printf("%d + %d : %d\n",matrix[i][j],matrix[i][j+1],desired);
				count++;
			}
			if (matrix[i][j] + matrix[i+1][j] == desired){
				printf("%d + %d : %d\n",matrix[i][j], matrix[i+1][j], desired);
				count++;
			}
			if (matrix[i][j] + matrix[i+1][j+1] == desired){
				printf("%d + %d : %d\n",matrix[i][j], matrix[i+1][j+1], desired);
				count++;
			}
		}
	}
	printf("%d",count);
	for(int i = 0; i<N; i++){
		free(matrix[i]);
	}
	free(matrix);
	return 0;
}