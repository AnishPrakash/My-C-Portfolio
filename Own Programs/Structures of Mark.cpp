#include <stdio.h>
typedef struct person{
	int marks;
}p;
int main(){
	p student;
	int sum = 0;
	for (int i = 0; i<2; i++){
		scanf("%d",&student.marks);
		sum+=student.marks;
	}
	printf("%d",sum);
	return 0;
}