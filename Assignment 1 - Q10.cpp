#include <stdio.h>
int main(){
	int basic_salary;
	float HRA, DA;
	double gross_salary;
	printf("Enter your salary!\n");
	scanf("%d",&basic_salary);
	if (basic_salary < 15000){
		HRA = 1.5 * basic_salary;
		DA = 0.9 * basic_salary;
		gross_salary = basic_salary + HRA + DA;
		printf("%0.2lf",gross_salary);
	}
	else {
		HRA = 5000;
		DA = 0.98 * basic_salary;
		gross_salary = basic_salary + HRA + DA;
		printf("%0.2lf",gross_salary);
	}
	return 0;
	
}