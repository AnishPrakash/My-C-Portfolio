#include <stdio.h>
#include <string.h>
int main(){
	char a[100];
	scanf("%s",&a);
	int l = strlen(a);
	for(int i = 1; i<=l; i++){
		printf("%*.*s\n",l,i,a);
	}
	for(int i = l-1; i>=0; i--){
		printf("%*.*s\n",l,i,a);
	}
	return 0;	
}