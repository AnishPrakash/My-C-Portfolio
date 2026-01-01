#include <stdio.h>
int main(){
	int num,left;
	float tax;
	scanf("%d",&num);
	if (num < 300000){
		tax = 0;
	}
	else if (num > 300000 && num < 600000){
		left = 600000 - num;
		tax = 0.05*left;
	}
	else if (num > 600000 && num < 900000){
		left = 900000 - num;
		tax = 15000 + 0.1*left;
	}
	else if (num > 900000 && num < 1200000){
		left = 1200000 - num;
		tax = 45000+0.15*left;
	}
	else if (num > 1200000 && num < 1500000){
		left = 1500000 - num;
		tax = 90000+0.2*left;
	}
	else if (num == 300000){
		tax = 0;
	}
	else if (num == 600000){
		tax = 15000;
	}
	else if (num == 900000){
		tax = 45000;
	}
	else if (num == 1200000){
		tax = 90000;
	}
	else if (num == 1500000){
		tax = 300000;
	}
	else {
		left = num - 1500000;
		tax = 300000 + 0.3*left;
	}
	printf("%.0f",tax);
	return 0;
}