#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
	char s[100];
	char n[100];
	printf("Enter string: ");
	scanf("%[^\n]%*c",&s);
	int l = strlen(s);
	int count = 0;
	for (int i = 0; i<l; i++){
		n[i] = tolower(s[i]);
	}
	for (int i = 0; i<l; i++){
		if (n[i] =='a' || n[i] =='e' || n[i] == 'i'|| n[i] == 'o'|| n[i] == 'u'){
			count++;
		}
	}
	printf("Number of vowels: %d",count);
	return 0;
}