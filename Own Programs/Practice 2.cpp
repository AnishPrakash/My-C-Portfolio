#include <stdio.h>
int sum1(int matrix[][2],int r){
	int sum = 0;
	for(int i = 0; i<r; i++){
		sum+=matrix[i][1];
	}
	return sum;
}
int main(){
	int n;
	scanf("%d",&n);
	int matrix[n][2];
	for(int i = 0; i<n; i++){
		for(int j = 0; j<2; j++){
			scanf("%d",&matrix[i][j]);
		}
	}
	int ans = sum1(matrix,n);
	if(ans<18){
		printf("Not enough credits");
	}
	else{
		printf("Yayy");
	}
	return 0;
}