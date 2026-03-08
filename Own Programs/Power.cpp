#include <stdio.h>
int main(){
	int b,e;
	printf("Enter base: ");
	scanf("%d",&b);
	printf("Enter exponent: ");
	scanf("%d",&e);
	int r = 0;
	int result = 1;
	while(r!=e){
		result *= b;
		r++;
	}
	printf("Result: %d",result);
	return 0;
}