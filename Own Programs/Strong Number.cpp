#include <stdio.h>
int fact(int num){
	if (num == 1)
		return 1;
	else
		return num*fact(num-1);
}
int main(){
	int n;
	printf("Enter number : ");
	scanf("%d",&n);
	int sum = 0;
	while(n!=0){
		int r = n%10;
		int l = fact(r);
		sum += l;
		n/=10;
	}
	if (sum == n){
		printf("The given number is a strong number.");
	}
	else{
		printf("The given number is NOT a strong number.");
	}
	return 0;
}