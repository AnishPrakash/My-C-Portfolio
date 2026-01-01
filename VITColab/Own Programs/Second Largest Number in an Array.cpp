#include <stdio.h>
int main(){
	int size;
	printf("Enter size: ");
	scanf("%d",&size);
	int arr[size];
	printf("Enter elements: ");
	for (int i = 0; i<size; i++){
		scanf("%d",&arr[i]);
	}
	int max = -999999;
	for (int i = 0; i<size; i++){
		if(arr[i]>max){
			max = arr[i];
		}
	}
	int max1 = -999999;
	for(int i = 0; i<size; i++){
		if(arr[i]>max1 && arr[i]!=max){
			max1 = arr[i];	
		}
	}
	printf("The Second Largest element is: %d",max1);
	return 0;
}