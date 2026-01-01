#include <stdio.h>
int sum(int num){
	if (num == 0)
		return 0;
	else
		return num + sum(num - 1);
}
int main(){
	int n;
	printf("Enter number : ");
	scanf("%d",&n);
	printf("Sum : %d",sum(n));
	return 0;
}