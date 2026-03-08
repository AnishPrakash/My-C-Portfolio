#include <stdio.h>
void processTransaction(int a){
	int static counter = 0;
	if(counter == -1){
		printf("Status: Account Frozen\n");
	}
	if(a>50000){
		counter++;
		if (counter==3){
			counter = -1;
			printf("Status: BLOCKED (%d)\n",counter);
		}
		else{
			printf("Status: Warning (%d)\n",counter);
		}
	}
	else{
		if (counter<3 && counter!= -1){
			counter = 0;
			printf("Status: Safe (%d)\n",counter);	
		}
	}
}
int main(){
	int N;
	printf("Input: \n");
	scanf("%d",&N);
	printf("\n");
	for(int i = 0; i<N; i++){
		int amount = 0;
		scanf("%d",&amount);
		processTransaction(amount);
	}
	return 0;
}