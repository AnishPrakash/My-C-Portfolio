#include <stdio.h>
#include <ctype.h>
int main(){
	char a[100],b;
	printf("Enter your string. ");
	scanf("%[^\n]%*c",&a);
	printf("Find char : ");
	scanf("%c",&b);
	int i = 0, count = 0;
	while(a[i]!='\0'){
		if (tolower(a[i])==b){
			count++;
		}
		i++;
	}
	printf("Freq of '%c' is %d",b,count);
	return 0;
}