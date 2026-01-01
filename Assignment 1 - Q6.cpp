#include <stdio.h>
int main(){
	int students,team_size,remainder,members;
	scanf("%d%d",&students,&team_size);
	members = students/team_size;
	remainder = students%team_size;
	printf("The number of students in each team is %d and the number of students left out is %d",members,remainder);
	return 0;
}