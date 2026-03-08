#include <stdio.h>
#include <string.h>
int main(){
	char str[100];
	scanf("%[^\n]s",str);
	int len = strlen(str);
	char * l = str;
	char * r = str+len-1;
	while(l<r){
		char temp;
		temp = *l;
		*l = *r;
		*r = temp;
		l++;
		r--;
	}
	printf("%s\n",str);
	l = str;
	r = str+len-1;
	int isPalindrome = 1;
	for (int i = 0; i<len; i++){
		if(*(l+i) != *(r-i)){
			isPalindrome = 0;
			break;
		}
	}
	if(isPalindrome){
		printf("It is a palindrome.");
	}
	else{
		printf("It is not a palindrome.");
	}
	return 0;
}