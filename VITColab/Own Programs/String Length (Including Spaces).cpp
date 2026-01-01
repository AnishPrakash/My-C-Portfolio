#include <stdio.h>
int main(){
	char a[100];
	printf("Enter your string. (Limit upto 100 Characters including space) ");
	scanf("%[^\n]%*c",&a);
	int count = 0;
	int i = 0;
	while(a[i]!='\0'){
		count++;
		i++;
	}
	printf("Length of given string is %d.",count);
	return 0;
}