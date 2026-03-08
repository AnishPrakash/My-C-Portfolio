#include <stdio.h>
#include <string.h>
void printSubsequence(char * in, char * out, int i, int j, int n){
	if(i == n){
		for (int k = 0; k<j; k++){
			printf("%c ",out[k]);
		}
		printf("\n");
		return;
	}
	out[j] = in[i];
	printSubsequence(in,out,i+1,j+1,n);
	printSubsequence(in,out,i+1,j,n);
	
}
int main(){
	char input[100];
	scanf("%[^\n]%*c",input);
	int n = strlen(input);
	char output[100];
	printSubsequence(input,output,0,0,n);
	return 0;	
}