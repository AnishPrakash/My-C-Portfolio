#include <stdio.h>
int main(){
	int p,r,t;
	float si;
	printf("Principal, Rate and Time: ");
	scanf("%d %d %d",&p,&r,&t);
	si = (p*r*t)/(float)100;
	printf("Simple Interest: %.2f",si);
	return 0;
}