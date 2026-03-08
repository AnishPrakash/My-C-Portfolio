#include <stdio.h>
void res(int * ptr){
	int n = 50;
	ptr = &n;
	*ptr = 50;
}
int main(){
	int temp = 30, *ptr;
	ptr = &temp;
	res(ptr);
	printf("%d",*ptr);
	return 0;
}