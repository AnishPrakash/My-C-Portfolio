#include <stdio.h>
int main(){
	int num,find,count = 0;
	scanf("%d",&num);
	scanf("%d",&find);
	while (num!=0){
		int r = num%10;
		num/=10;
		if (r == find){
			count++;
		}
	}
	printf("%d",count);
	return 0;
}