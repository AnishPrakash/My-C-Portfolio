#include <stdio.h>
int main(){
	int cost,num;
	double price;
	scanf("%d%d",&cost,&num);
	if (num<50){
		price = cost*num;
	}
	else if(num>= 50 && num <=100){
		price = cost*num - 0.1*cost*num;
	}
	else if(num>=101 && num <= 200){
		price = cost*num - 0.2*cost*num;
	}
	else if(num>=201 && num <= 400){
		price = cost*num - 0.3*cost*num;
	}
	else if(num >= 401 && num <= 500){
		price = cost*num - 0.4*cost*num;
	}
	else{
		price = 0.5*cost*num;
	}
	printf("%.2lf",price);
	return 0;
}