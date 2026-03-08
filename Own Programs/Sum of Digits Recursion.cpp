#include <stdio.h>
void recursive(int n){
	int sum = 0;
	while (n!=0){
		int r = n%10;
		sum+=r;
		n/=10;
	}
	printf("Sum of digits: %d",sum);
}
int main(){
	printf("Enter number: ");
	int n;
	scanf("%d",&n);
	recursive(n);
	return 0;
}