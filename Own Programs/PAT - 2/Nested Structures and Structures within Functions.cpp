#include <stdio.h>
struct Date{
	int day;
	int month;
	int year;
};
struct Employee{
	int emp_id;
	struct Date d;
};
struct Employee input(){
	struct Employee e;
	scanf("%d", &e.emp_id);
	scanf("%d %d %d",&e.d.day,&e.d.month,&e.d.year);
	return e;
}
void print(struct Employee e){
	printf("Employee %d joined on %d/%d/%d",e.emp_id,e.d.day,e.d.month,e.d.year);
}
int main(){
	struct Employee e = input();
	print(e);
	return 0;
}