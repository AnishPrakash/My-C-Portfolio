#include <stdio.h>
int main(){
	int n;
	printf("Enter N\n");
	scanf("%d",&n);
	int sum = 0;
	printf("Sum (");
	for(int i = 1; i<=n; i++){
		if(i%2 == 0){
			sum += i;
			printf("%d",i);
			if (i!=n){
				printf("+");
			}
		}
	}
	printf("): %d",sum);
	return 0;
}