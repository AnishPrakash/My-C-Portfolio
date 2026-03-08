#include <stdio.h>
int main(){
	char string[100];
	printf("Please enter your string!\n");
	fgets(string,sizeof(string),stdin);
	int l = -1;
	int i = 0;
	while(string[i]!='\0'){
		l++;
		i++;
	}
	char * p1 = string;
	char * p2 = string + l - 1;
	int isPalindrome = 1;
	for (int i = 0; i<l; i++){
		if(*(p1+i) != *(p2-i)) 
			isPalindrome = 0;
	}
	if(isPalindrome){
		printf("Palindrome");
	}
	else{
		printf("Not Palindrome");
	}
	return 0;
}