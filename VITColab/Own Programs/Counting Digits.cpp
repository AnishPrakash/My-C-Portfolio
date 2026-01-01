#include <stdio.h>
int main(){
	int n;
	printf("Enter number: ");
	scanf("%d",&n);
	int count = 0;
	while (n!=0){
		n/=10;
		count++;
	}
	printf("Total digits: %d",count);
	return 0;
}