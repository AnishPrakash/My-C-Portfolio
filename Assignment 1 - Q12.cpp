#include <stdio.h>
int main(){
	int g1,g2,g3,g4,g5;
	float avg;
	scanf("%d %d %d %d %d",&g1,&g2,&g3,&g4,&g5);
	avg = (g1+g2+g3+g4+g5)/float(5);
	if (g1 >2 && g2 > 2 && g3 > 2 && g4 > 2 && g5 > 2)
	{
		if (g1 == 5 || g2 == 5|| g3 == 5|| g4 == 5|| g5 == 5)
		{
			if (avg>=4.0)
				printf("Yes");
			else
				printf("No");
		}
		else {
			printf("No");
		}
	}
	else {
		printf("No");
	}
	return 0;
}