#include <stdio.h>
int main(){
	int size,X,found=0;
	scanf("%d",&size);
	int coin[size];
	for (int i = 0;i<size;i++){
		scanf("%d",&coin[i]);
	}
	scanf("%d",&X);
	for (int i =0; i<size;i++){
		for(int j = i+1;j<size;j++){
			if (coin[i]==coin[j]||coin[i]>coin[j]){
				printf("-1");
				return 0;
			}
		}
		if(coin[i]==X){
			printf("%d",i);
			found++;
			return 0;
		}
	}
	if(found==0){
		for (int i = 0; i<size;i++){
			if(X<coin[i]||X==coin[i]){
				printf("%d",i);
				return 0;
			}
		}
	}
	return 0;
}