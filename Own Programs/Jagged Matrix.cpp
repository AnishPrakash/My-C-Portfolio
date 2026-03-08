#include <stdio.h>
#include <stdlib.h>
int main(){
	int N;
	printf("Enter number of students: ");
	scanf("%d",&N);
	int** matrix = (int**)malloc(N*sizeof(int*));
	for(int i = 0; i<N; i++){
		int n;
		printf("Student %d subjects: ",i+1);
		scanf("%d",&n);
		printf("Enter marks: ");
		matrix[i] = (int*)malloc(n*sizeof(int));
		for(int j = 0; j<n; j++){
			scanf("%d",&matrix[i][j]);
		}
		int sum = 0;
		for(int j = 0; j<n; j++){
			sum+=matrix[i][j];
		}
		printf("Student %d Average: %d\n",i+1,(sum/n));
	}
	for(int i = 0; i<N; i++){
		free(matrix[i]);
	}
	free(matrix);
	return 0;
}
