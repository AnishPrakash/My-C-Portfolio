#include <stdio.h>
int fact(int num){
	if (num == 1)
		return 1;
	else
		return num * fact(num - 1);
}
int main(){
	printf("Enter Number: ");
	int n;
	scanf("%d",&n);
	printf("Factorial is: %d",fact(n));
	return 0;
}