#include <stdio.h>
void print(){
	int static count = 0;
	count++;
	printf("%d\n",count);
}
int main(){
	for (int i = 0; i<4; i++){
		print();
	}
	return 0;
}