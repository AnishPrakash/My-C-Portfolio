#include <stdio.h>
int main(){
	char s[100];
	scanf("%[^\n]%*c",s);
	int word = 0;
	printf("%d",word);
	return 0;
}