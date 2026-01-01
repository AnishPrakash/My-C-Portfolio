#include <stdio.h>
int main(){
	int T;
	scanf("%d",&T);
	int I = 0;
	while(I<T){
		int n,start,end;
		scanf("%d",&n);
		int wind[n];
		for(int i =0; i<n; i++){
			scanf("%d",&wind[i]);
		}
		scanf("%d %d",&start,&end);
		int empty[n];
		int count = 0;
		int j = 0;
		for (int i = 0;i<n;i++){
			if (wind[i]>=start && wind[i]<=end){
				empty[j++] = wind[i];
				count++;
			}
		}
		if (count == 0){
			printf("No days found");
		}
		else{
			for (int i = 0; i<count; i++){
				printf("%d ",empty[i]);
			}
		}
		printf("\n");
		I++;
	}
	return 0;
}