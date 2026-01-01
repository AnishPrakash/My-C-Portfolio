#include <stdio.h>
int main(){
	int weeks, problems, count = 0;
	printf("Enter the no. of weeks\n");
	scanf("%d",&weeks);
	int arr[weeks];
	printf("No. of problems solved.\n");
	for (int i = 0; i<weeks;i++){
		scanf("%d",&arr[i]);
		if (arr[i]>=10){
			count++;
		}
	}
	printf("\nWeeks where at least 10 problems were solved: %d",count);
	return 0;
}