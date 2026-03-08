#include <stdio.h>
int main(){
	printf("Enter decimal number: ");
	int n;
	scanf("%d",&n);
	int arr[n];
	int i = 0;
	int count = 0;
	while(n!=0){
		arr[i] = n%2;
		n = n/2;
		i++;
		count++;
	}
	for (int j = count-1; j>=0; j--){
		printf("%d",arr[j]);
	}
	return 0;
}