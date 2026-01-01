#include <stdio.h>
int armstrong(int num){
	int num1 = num;
	int sum = 0;
	while (num1!=0){
		int r = num1%10;
		int cube = r*r*r;
		sum+=cube;
		num1/=10;
	}
	return sum;
}
int main(){
	for (int i = 1; i<=1000; i++){
		int l = armstrong(i);
		if (l == i){
			printf("%d ",i);
		}
		else{
			continue;
		}
	}
	return 0;
}