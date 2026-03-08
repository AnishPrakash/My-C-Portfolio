#include <stdio.h>
int main(){
	int r,c;
	printf("Enter the no. of locations: ");
	scanf("%d",&r);
	printf("Enter the no. of time intervals: ");
	scanf("%d",&c);
	int matrix[r][c];
	printf("Enter the humidity readings: ");
	for (int i = 0; i<r; i++){
		for (int j = 0; j<c; j++){
			scanf("%d",&matrix[i][j]);
		}
	}
	printf("Original Matrix: \n");
	for (int i = 0; i<r; i++){
		for (int j = 0; j<c; j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
	int arr[r*c];
	int total = 0;
	for (int i = 0; i<r; i++){
		int dec = 0, inc = 0;
		for (int j = 0; j<c-1; j++){
			if(matrix[i][j] < matrix[i][j+1]){
				inc++;
			}
			if(matrix[i][j]>matrix[i][j+1]){
				dec++;
			}
		}
		if (dec == c || inc == c){
			arr[total] = i;
			total++;
			continue;
		}
		int m1,m2,m3,flag = 0;
		for (int j = 0; j<c-2; j++){
			if (matrix[i][j] == matrix[i][j+1] && matrix[i][j+1] == matrix[i][j+2]){
				flag = 1;
				break;
			}
		}
		if (flag){
			arr[total] = i;
			total++;
			continue;
		}
	}
	printf("Indices of all inconsistent locations: \n");
	for (int i = 0; i<total; i++){
		printf("%d ",arr[i]);
	}
	printf("Total no. of inconsistent locations is %d",total);
	return 0;
}