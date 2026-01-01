#include <stdio.h>
int main(){
	int n;
	printf("Enter the size of the square matrix: ");
	scanf("%d",&n);
	int matrix[n][n];
	for (int i = 0; i<n; i++){
		for (int j = 0; j<n; j++){
			scanf("%d",&matrix[i][j]);
		}
	}
	int found = 0;
	int diff = 0;
	for (int i = 0; i<n; i++){
		for (int j = 0; j<n ; j++){
			if(i == j && matrix[i][j]==1){
				found++;
			}
			if (i!=j && matrix[i][j]==0){
				diff++;
			}
		}
	}
	if (found == n && diff == n*n - found){
		printf("The given matrix is an Identity Matrix");
	}
	else{
		printf("It is not an Identity Matrix");
	}
	return 0;
}