#include <stdio.h>
int main(){
	int x,a,b,profit;
	scanf("%d%d%d",&x,&a,&b);
	profit = x*a - x*b - 100;
	printf("%d",profit);
	return 0;
}