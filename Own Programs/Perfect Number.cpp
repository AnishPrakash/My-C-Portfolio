#include <stdio.h>
int main(){
	int n;
	printf("Enter N : ");
	scanf("%d",&n);
	int sum = 0;
	for (int i = 1; i<n; i++){
		if(n%i == 0){
			sum+= i;
		}
	}
	if (sum == n){
		printf("%d is a perfect number.",n);
	}
	else{
		printf("%d is NOT a perfect number.",n);
	}
	return 0;
}