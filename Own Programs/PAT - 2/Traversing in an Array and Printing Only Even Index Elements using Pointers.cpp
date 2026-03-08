#include <stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	int * ptr = arr;
	for (int i = 0; i<n; i++){
		scanf("%d",ptr+i);
	}
	ptr = arr;
	for (int i = 0; i<n; i+=2){
		if(i>0) printf(" ");
		printf("%d",*(ptr+i));
	}
	return 0;
}