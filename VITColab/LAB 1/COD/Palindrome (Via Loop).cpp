//PALINDROME VIA LOOPING
#include <stdio.h>
int main(){
	int num,a=0;
	scanf("%d",&num);
	int n = num;
	while(n!=0){
		int r = n%10;
		a = (a*10)+r;
		n/=10;
	}
	printf("%d\n",a);
	if (a==num){
		printf("Palindrome");
	}
	else{
		printf("Not a Palindrome");
	}
	return 0;
}