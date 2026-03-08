#include <stdio.h>
int main(){
	int c;
	printf("Enter Temperature in Celsius: ");
	scanf("%d",&c);
	float f = (c*9)/(float)5 + 32;
	printf("Temperature in Fahrenheit: %0.2f",f);
	return 0;
}