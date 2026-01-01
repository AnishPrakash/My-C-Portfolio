#include <stdio.h>
int main(){
    int start,end,sum = 0;
    int num,i,isPrime;
    scanf("%d %d", &start,&end);
    for (num = start; num<=end; num++){
        if (num < 2){
            continue;
        }
        isPrime = 1;
        for (i=2; i*i <=num; i++){
            if(num%i == 0){
                isPrime = 0;
                break;
            }
        }
        if (isPrime == 1){
            sum += num;
        }
    }
    printf("%d",sum);
    return 0;
}