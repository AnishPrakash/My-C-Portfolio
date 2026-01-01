#include <stdio.h>
int series(int);
int main(){
	int n;
	scanf("%d",&n);
	series(n);
	return 0;
}
int series(int n){
	int i = 0;
	if (i == n){
		return printf("%d",n);
	}
	else{
		i++;
		printf("%d ",i);
		return series(n-1);
	}
}