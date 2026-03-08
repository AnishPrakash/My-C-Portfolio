#include <stdio.h>
void swapByValue(int a, int b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void swapByRef(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int main(){
	int a,b;
	printf("Enter two numbers: ");
	scanf("%d %d",&a,&b);
	swapByValue(a,b);
	printf("After swapByValue: a = %d, b = %d\n",a,b);
	swapByRef(&a,&b);
	printf("After swapByRef: a = %d, b = %d",a,b);
	return 0;
}