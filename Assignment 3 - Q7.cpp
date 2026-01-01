#include <stdio.h>
int main(){
	int N,pass = 0, fail = 0;
	printf("Enter the number of students in the class\n");
	scanf("%d",&N);
	int arr[N];
	printf("Enter the marks of the students\n");
	for (int i = 0; i < N; i++){
		scanf("%d",&arr[i]);
		if (arr[i] == -1){
			continue;
		}
		else{
			if (arr[i]<50){
				fail++;
			}
			else{
				pass++;
			}
		}
		
	}
	double passed = ((double)pass/(double)N)*100;
	double percentage = (int)(passed * 100.0) / 100.0;
	printf("Number of passed students is %d and the number of failed students is %d\n",pass,fail);
	printf("Pass Percentage: %.2lf%%",percentage);
	return 0;
}