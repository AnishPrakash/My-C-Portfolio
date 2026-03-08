#include <stdio.h>
struct complex{
	float real,img;
};
struct complex read_complex(){
	struct complex c;
	scanf("%f",&c.real);
	scanf("%f",&c.img);
	return c;
}
struct complex add_complex(struct complex a, struct complex b){
	struct complex c;
	c.real = a.real+b.real;
	c.img = a.img+b.img;
	return c;
}
struct complex sub_complex(struct complex a, struct complex b){
	struct complex c;
	c.real = a.real-b.real;
	c.img = a.img-b.img;
	return c;
}
struct complex mul_complex(struct complex a, struct complex b){
	struct complex c;
	c.real = a.real*b.real - a.img*b.img;
	c.img  = a.real*b.img +a.img*b.real;
	return c;
}
struct complex div_complex(struct complex a, struct complex b){
	struct complex c;
	c.real = (a.real*b.real+a.img*b.img)/(b.real*b.real + b.img*b.img);
	c.img = (a.img*b.real-a.real*b.img)/(b.real*b.real+b.img*b.img);
	return c;
}
void display_complex(struct complex c){
	if (c.img<0){
		printf("%f %fi\n",c.real,c.img);
	}
	else{
		printf("%f + %fi\n",c.real,c.img);
	}
}
int main(){
	struct complex a,b,c;
	a = read_complex();
	b = read_complex();
	c = add_complex(a,b);
	display_complex(c);
	c = sub_complex(a,b);
	display_complex(c);
	c = mul_complex(a,b);
	display_complex(c);
	c = div_complex(a,b);
	display_complex(c);
	return 0;
}
