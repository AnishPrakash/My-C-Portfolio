//Linear Search
#include <stdio.h>
int main(){
	int n, target;
	printf("Enter the Size of the Array - \n");
	scanf("%d",&n);
	printf("Enter the Target Value - \n");
	scanf("%d",&target);
	printf("Enter the Elements for the Array - \n");
	int arr[n], found = -1;
	for (int i = 0; i<n; i++){
		scanf("%d",&arr[i]);
		if (arr[i] == target){
			found = i;
		}
	}
	if (found!=-1)
		printf("\nTarget Element %d found at index %d.",target,found);
	else
		printf("\nTarget Element %d not found in the provided Array.");
	return 0;
}