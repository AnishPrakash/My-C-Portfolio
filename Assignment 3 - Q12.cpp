#include <stdio.h>
int len(int num);
int main(){
	int N;
	scanf("%d",&N);
	int l = len(N);
	int arr[l];
	for (int i = l-1; i>=0;i--){
		arr[i] = N%10;
		N/=10;
	}
	for (int j = 0; j<l;j++){
		for (int k = j+1; k<l; k++){
			if (arr[j]>arr[k]){
				int a = arr[j];
				arr[j] = arr[k];
				arr[k] = a;
			}
		}
	}
	for (int t = 0; t<l;t++){
		if (arr[t]%2 == 0){
			continue;
		}
		if (t>0 && arr[t] == arr[t-1]){
			continue;
		}
		int count = 0;
		for (int b = 0; b<l;b++){
			if (arr[b]==arr[t]){
				count++;
			}
		}
		if (count%2 != 0){
			printf("%d",arr[t]);
			return 0;
		}
	}
	printf("-1");
	return 0;
}
int len(int num){
	int c = 0;
	while(num!=0){
		c++;
		num/=10;
	}
	return c;
}
