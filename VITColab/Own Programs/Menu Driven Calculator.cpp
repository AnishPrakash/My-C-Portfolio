#include <stdio.h>
//Fix: Add a space before %c in scanf(" %c", ...) to tell C to ignore whitespace (like the Enter key).
int main(){
	int n1,n2;
	char a,b;
	do{
		printf("Enter 2 numbers: ");
		scanf("%d %d",&n1,&n2);
		printf("Choose (+, -, *, /): ");
		scanf(" %c",&a);
		int answer = 0;
		float answer1 = 0.00;
		switch(a){
			case '+':
				answer = n1+n2;
				printf("Result: %d\n",answer);
				break;	
			case '-':
				answer = n1-n2;
				printf("Result: %d\n",answer);
				break;
			case '*':
				answer = n1*n2;
				printf("Result: %d\n",answer);
				break;
			case '/':
				if (n2!=0){
					answer1 = n1/(float)n2;
					printf("Result: %.2f\n",answer1);
					break;
				}
				else{
					printf("Zero Division Error\n");
					break;
				}
			default:
				printf("Invalid Choice of Operation\n");			
		}
		printf("Do you want to continue? (y/n): ");
		scanf(" %c",&b);
	}while (b!='n');
	return 0;
}