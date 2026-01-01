#include <stdio.h>
int main(){
	printf("Enter three numbers: ");
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	int l = (a>b&&a>c)?a:((b>c)?b:c);
	printf("The largest number is: %d",l);
	return 0;
}