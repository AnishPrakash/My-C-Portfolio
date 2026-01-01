#include <stdio.h>
int main(){
	printf("Enter N: ");
	int N;
	scanf("%d",&N);
	if (N == 1){
		printf("No Prime Numbers");
	}
	else{
		for (int i = 2; i<=N; i++){
			int count = 0;
			for (int j = 1; j<=i; j++){
				if(i%j == 0){
					count++;
				}
			}
			if (count!=2){
				continue;
			}
			else{
				printf("%d ",i);
			}
		}
	}
	return 0;
}