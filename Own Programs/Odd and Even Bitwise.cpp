#include <stdio.h>
int main(){
	printf("Enter a number: ");
	int n;
	scanf("%d",&n);
	if (n&1)
		printf("%d is Odd",n);
	else
		printf("%d is Even",n);
	return 0;
}