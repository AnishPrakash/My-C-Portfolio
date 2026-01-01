#include <stdio.h>
int main(){
	int x1,y1,x2,y2;
	float m1,m2;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	m1 = (x1+x2)/2.0;
	m2 = (y1+y2)/2.0;
	printf("%.1f\n%.1f",m1,m2);
	return 0;
}