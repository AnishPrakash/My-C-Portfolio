#include <stdio.h>
int main(){
	printf("Enter Year: ");
	int y;
	scanf("%d",&y);
	if (y%400==0 || (y%100!=0 && y%4==0)){
		printf("%d is a Leap Year.",y);
	}
	else{
		printf("%d is not a Leap Year.",y);
	}
	return 0;
}