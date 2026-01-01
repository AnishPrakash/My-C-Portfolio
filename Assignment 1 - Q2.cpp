#include <stdio.h>
int main(){
	char event_name[50],event_type[50],paid_entry;
	int people;
	double expenses;
	scanf("%[^\n]%*c\n%s\n%d\n%c\n%lf",&event_name,&event_type,&people,&paid_entry,&expenses);
	printf("%s\n%s\n%d\n%c\n%.1lf",event_name,event_type,people,paid_entry,expenses);
	return 0;
}