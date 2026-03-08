#include <stdio.h>
#include <limits.h>
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	int found = 1;
	int temp = -1;
	for(int i = 0; i<n; i++){
		scanf("%d",&arr[i]);
	}
	for(int i = 0; i<n-1; i++){
		if(arr[i]>arr[i+1]){
			found = 0;
			break;
		}
	}
	if(found == 0){
		printf("list is not sorted\n");
		for(int i = 0; i<n-1; i++){
			for(int j = 0; j<n-i-1; j++){
				if(arr[j]>arr[j+1]){
					int temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
				}
			}
		}
		for(int i = 0; i<n; i++){
			printf("%d ",arr[i]);
		}
	}
	else{
		printf("list is sorted\n");
	}
	printf("\n");
	int temp1 = arr[1];
	arr[1] = arr[n-2];
	arr[n-2] = temp1;
	for(int i = 0; i<n; i++){
		printf("%d ",arr[i]);
	}
	return 0;
}