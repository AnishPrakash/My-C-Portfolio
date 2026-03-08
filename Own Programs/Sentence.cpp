#include <stdio.h>
#include <string.h>
#include <ctype.h>
void right_cyclic(char*w,int n){
	char temp[n];
	char c = w[n-1];
	temp[0] = c;
	for(int i = 0; i<n-1; i++){
		temp[i+1] = w[i];
	}
	strcpy(w,temp);
}
void left_cyclic(char*w, int n){
	char temp[n];
	char c = w[0];
	for(int i = 1; i<n; i++){
		temp[i-1] = w[i];
	}
	temp[n-1] = c;
	strcpy(w,temp);
}
int main(){
	char sentence[100];
	char words[100][20];
	scanf("%[^\n]%*c",sentence);
	char*token = strtok(sentence," ");
	int i = 0;
	while(token!=NULL){
		strcpy(words[i],token);
		i++;
		token = strtok(NULL," ");
	}
	for (int k = 0; k<i; k++){
		if(strlen(words[k])%2==0){
			left_cyclic(words[k],strlen(words[k]));
		}
		else{
			right_cyclic(words[k],strlen(words[k]));
		}
	}
	for (int j = 0; j<i; j++){
		printf("%s ",words[j]);
	}
	return 0;
}