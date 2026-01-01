#include <stdio.h>
int main(){
	int N, count = 0;
	scanf("%d",&N);
	int arr[N];
	for (int i = 0; i<N; i++){
		scanf("%d",&arr[i]);
	}
	for (int j = 1; j<=N; j++){
		if (arr[j-1]==arr[j]){
			continue;
		}
		else{
			count++;
		}
	}
	printf("%d",count);
	return 0;
}