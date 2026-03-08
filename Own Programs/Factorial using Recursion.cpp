#include <stdio.h>
int factorial(int);
int main(){
	int n;
	scanf("%d",&n);
	int answer = factorial(n);
	printf("%d",answer);
	return 0;
}
int factorial(int n){
	if (n == 1){
		return 1;
	}
	else if(n==0){
		return 1;
	}
	else{
		return n*factorial(n-1);
	}
}