#include <stdio.h>
int main(){
	int n;
	printf("Enter number: ");
	scanf("%d",&n);
	int rev = 0;
	while (n!=0){
		int r = n%10;
		rev = 10*rev + r;
		n/=10;
	}
	printf("Reversed Number: %d",rev);
	return 0;
}