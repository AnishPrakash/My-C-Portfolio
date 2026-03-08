#include <stdio.h>
int multiply(int a, int b){
	return a*b;
}
int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	int (* fptr)(int,int) = &multiply;
	printf("Product = %d",fptr(a,b));
	return 0;
}