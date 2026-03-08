//saddle element
#include <stdio.h>
#include <limits.h>
int main(){
	int T;
	scanf("%d",&T);
	int I = 0;
	while(I<T){
		int r,c;
		scanf("%d %d",&r,&c);
		int matrix[r][c];
		for(int i = 0; i<r; i++){
			for(int j = 0; j<c; j++){
				scanf("%d",&matrix[i][j]);
			}
		}
		int arr[r+c] = {0};
		int k = 0;
		for(int i = 0; i<r; i++){
			int min = INT_MAX;
			for(int j = 0; j<c; j++){
				if(matrix[i][j]<min){
					min = matrix[i][j];
					arr[k] = min;
				}
			}
			k++;
		}
		for(int i = 0; i<c; i++){
			int max = INT_MIN;
			for(int j = 0; j<r; j++){
				if(matrix[j][i]>max){
					max = matrix[j][i];
					arr[k] = max;
				}
			}
			k++;
		}
		for(int i = 0; i<k; i++){
			printf("%d ",arr[i]);
		}
		printf("\n");
		for(int i = 0; i<k; i++){
			int flag = 0;
			for(int j = i+1; j<k-1; j++){
				if(arr[i] == arr[j]){
					flag = 1;
					break;
				}
			}
			if(flag){
				printf("Saddle Element Present.");
				break;
			}
		}
		I++;  
	}
	return 0;
}