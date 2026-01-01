#include <stdio.h>
int main(){
    int start,end,sum,counter = 0;
    scanf("%d %d",&start,&end);
    for (int i = start; i<=end; i++){
        sum = 0;
        for (int j = 1; j<i;j++){
            if (i%j==0){
                sum += j;
            }
        }
        if (sum == i){
            printf("%d ",i);
            counter++;
        }
    }
    if (counter == 0){
        printf("No perfect numbers");
    }
    return 0;
}