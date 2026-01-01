#include <stdio.h>
int main(){
	int N;
	float sum = 0.0;
	scanf("%d",&N);
	float arr[N];
	for (int i = 0; i < N; i++){
		scanf("%f",&arr[i]);
		sum += arr[i];
	}
	for (int j = 1; j <= N; j++){
		for (int k = 0; k<=j; k++){
			if (arr[k]>arr[j]){
				float a = arr[j];
				arr[j] = arr[k];
				arr[k] = a;
			}
			else{
		 		continue;
			}	
		}
	}	
	float mean;
	mean = sum/N;
	float median;
	printf("%.2f\n",mean);
	if (N%2 != 0){
		int middle = (N+1)/2;
		median = arr[middle];
	}
	else{
		median = (arr[N/2] + arr[(N/2)+1])/2;
	}
	printf("%.2f",median);
	return 0;
}