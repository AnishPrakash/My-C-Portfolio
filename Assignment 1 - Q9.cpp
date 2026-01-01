#include <stdio.h>
int main(){
	int ticket;
	printf("Enter your ticket number!\n");
	scanf("%d",&ticket);
	if (ticket%10 == 5 || ticket%10 ==7){
		printf("Lucky Winner");
	}
	else {
		printf("Not a Lucky Winner");

	}
	return 0;
}