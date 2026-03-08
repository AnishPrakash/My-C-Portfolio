#include <stdio.h>
void printSubsequence(int in[], int out[], int i, int j, int n){
	if(i == n){
		for (int k = 0; k<j; k++){
			printf("%d ",out[k]);
		}
		printf("\n");
		return;
	}
	out[j] = in[i];
	printSubsequence(in,out,i+1,j+1,n);
	printSubsequence(in,out,i+1,j,n);
	
}
int main(){
	int n;
	printf("Enter the size of the array : ");
	scanf("%d",&n);
	int input[n];
	for (int i = 0; i<n; i++){
		scanf("%d",&input[i]);
	}
	int output[n];
	printSubsequence(input,output,0,0,n);
	return 0;	
}