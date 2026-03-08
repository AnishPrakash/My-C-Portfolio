#include <stdio.h>
#include <math.h>
int main(){
	printf("Enter coefficients a, b, c: ");
	double a,b,c,d,r1,r2,r,i;
	scanf("%lf %lf %lf",&a,&b,&c);
	d = (b*b - 4*a*c);
	if (d>0){
		r1 = (-b + sqrt(d))/(2*a);
		r2 = (-b - sqrt(d))/(2*a);
		printf("Roots are real and distinct: %.2lf and %.2lf",r1,r2);
	}
	else if (d == 0){
        r1 = r2 = -b / (2 * a);
        printf("Roots are real and equal: %.2lf and %.2lf", r1, r2);
    }
    else {
        r = -b / (2 * a);
        i = sqrt(-d) / (2 * a);
        printf("Roots are imaginary: %.2lf + %.2lfi and %.2lf - %.2lfi", r, i, r, i);
    }
    return 0;
}