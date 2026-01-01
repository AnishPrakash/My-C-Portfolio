#include <stdio.h>
int main(){
	char a[50],b[50];
	char result[100];
	printf("String 1: ");
	scanf("%[^\n]%*c",&a);
	printf("String 2: ");
	scanf("%[^\n]%*c",&b);
	int c1 = 0, c2 = 0;
	for(int i = 0; a[i]!='\0'; i++){
		c1++;
	}
	for (int i = 0; b[i]!='\0';i++){
		c2++;
	}
	for (int i = 0; i<c1; i++){
		result[i] = a[i];
	}
	int k = 0;
	for (int i = c1; i<c1+c2; i++){
		result[i] = b[k];
		k++;
	}
	printf("Concatenated Strings: %s",result);
	return 0;
}