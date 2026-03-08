#include <stdio.h>
int main(){
    int a = 10;
    int *p = &a;
    printf("%d %d %p %p",a,p,&a,&p);
}