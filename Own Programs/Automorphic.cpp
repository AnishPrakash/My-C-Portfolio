#include <stdio.h>
#include <stdbool.h>
bool isAutomorphic(int num){
	int square = num*num;
	int temp = num;
	while(temp>0){
		if(num%10 != square %10){
			return false;
		}
		num/=10;
		square/=10;
		temp/=10;
	}
	return true;
}
int main(){
	int num;
	scanf("%d",&num);
	if (isAutomorphic(num)){
		printf("%d is an automorphic.\n",num);
	}
	else{
		printf("%d is NOT an automorphic.\n",num);
	}
	return 0;
}