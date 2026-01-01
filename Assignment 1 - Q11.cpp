#include <stdio.h>
int main(){
	char choice;
	printf("Enter your choice among (O,A,B,C,D,U)\n");
	scanf("%c",&choice);
	switch(choice)
	{
		case 'O':
			printf("above 90%%");
			break;
		case 'A':
			printf("above 80%%");
			break;
		case 'B':
			printf("above 70%%");
			break;
		case 'C':
			printf("above 60%%");
			break;
		case 'D':
			printf("above 50%%");
			break;
		case 'U':
			printf("fail");
			break;
		default:
			printf("Invalid choice.!");
	}
	return 0;
	
}