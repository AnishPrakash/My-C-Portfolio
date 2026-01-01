#include <stdio.h>
int sum(int num);
int product(int num);
int main(){
	int start,end,addition,multiply,answer = 0;
	scanf("%d %d",&start,&end);
	for (int i = start; i <= end; i++){
		addition = sum(i);
		multiply = product(i);
		if (addition < multiply){
			answer += i; 
		}
		else {
			continue;
		}
	}
	printf("%d",answer);
	return 0;
}
int sum(int num){
	int r;
	int s = 0;
	while(num!=0){
		r = num%10;
		s = s + r;
		num/=10;
	}
	return s;
}
int product(int num){
	int p = 1;
	int r;
	while(num!=0){
		r = num%10;
		p = p*r;
		num/=10;
	}
	return p;
}