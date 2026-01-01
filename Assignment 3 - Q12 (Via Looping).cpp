//Q12 of Assignment 3 via Looping
#include <stdio.h>
int main(){
	int num, count = 0;
	int current_min = 10000;
	scanf("%d",&num);
	int num1 = num;
	while (num!=0){
		int r = num%10;
		int a = 0;
		a = a+r;
		if (a<current_min&&a%2!=0){
			current_min = a;
		}
		num/=10;
	}
	while(num1!=0){
		int r = num1%10;
		if (r == current_min){
			count++;
		}
		num1/=10;
	}
	if (count == 0 || count%2 == 0){
		printf("-1");
	}
	else{
		printf("%d",current_min);
	}
	return 0;
}