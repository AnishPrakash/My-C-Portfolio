#include <stdio.h>
#include <ctype.h>
int main(){
	char a[100],b[100];
	printf("String 1: ");
	scanf("%[^\n]%*c",&a);
	printf("String 2: ");
	scanf("%[^\n]%*c",&b);
	int found = 0;
	for (int i = 0; a[i]!='\0'; i++){
		if (tolower(a[i])==tolower(b[i])){
			continue;
		}
		else{
			found = -1;
			break;
		}
	}
	if (found == 0){
		printf("Strings are Equal.");
	}
	else{
		printf("Strings are Not Equal.");
	}
	return 0;
}