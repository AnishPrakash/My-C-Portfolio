#include <stdio.h>
int main(){
	char name[50];
	printf("Enter your name:\n");
	scanf("%s",name);
	printf("Hello %s! Welcome to BCSE102L course.",name);
	return 0;
}