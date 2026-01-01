#include <stdio.h>
int main(){
	int T,I=0;
	scanf("%d",&T);
	while(I<T){
		int n;
		scanf("%d",&n);
		int arr[n][n];
		for (int i = 0; i<n; i++){
			for (int j = 0; j<n; j++){
				scanf("%d",&arr[i][j]);
			}
		}
		int sum1=0,sum2=0,sum3=0,sum4=0;
		for (int i = 0; i<(n/2);i++){
			for (int j = 0; j<(n/2); j++){
				sum1+=arr[i][j];
			}
			for (int k = (n/2); k<n; k++){
				sum2+=arr[i][k];
			}
		}
		for (int i = (n/2); i<n; i++){
			for (int j = 0; j<(n/2); j++){
				sum3+=arr[i][j];
			}
			for (int k = (n/2);k<n;k++){
				sum4+=arr[i][k];
			}
		}
		printf("%d %d %d %d\n",sum1,sum2,sum3,sum4);
		I++;
	}
	return 0;
}