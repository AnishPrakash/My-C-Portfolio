#include <stdio.h>
int main(){
	char a[50];
	printf("Enter a string: ");
	scanf("%s",&a);
	int l = 0;
	for (int i = 0; a[i]!='\0'; i++){
		l++;
	}
	int found = 0;
	for (int i = 0; i<l/2; i++){
		if (a[i]==a[l-1-i]){
			continue;
		}
		else{
			found++;
			break;
		}
	}
	if (found==0){
		printf("Palindrome");
	}
	else{
		printf("Not Palindrome");
	}
	return 0;
}