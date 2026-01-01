#include <stdio.h>
int main(){
	int num,r,abs,last_digit,answer;
	scanf("%d",&num);
	if (num < 10){
		printf("Invalid Input");
	}
	else{
		last_digit = num%10;
		while(num>0){
			r = num;
			num = num/10;
		}
		abs = r - last_digit;
		if (abs < 0){
			answer = -abs;
		}
		else{
			answer = abs;
		}
		printf("%d",answer);
	}
	return 0;
}