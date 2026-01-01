#include <stdio.h>
int main(){
    int n,sum = 0,steps = 0,r = 0;
    scanf("%d",&n);
    if (n >= 10){
        while (n!=0){
            r = n%10;
            sum = r+sum;
            n/=10;
        }
        steps++;
        int answer = sum;
        while (answer>=10){
            int r1 = 0;
            while(answer!=0){
                r = answer%10;
                r1 = r+r1;
                answer/=10;
            }
            answer = r1;
            steps++;
        }
        printf("Digital Root: %d\n",answer);
        printf("Number of Steps: %d",steps);
    }
    else{
        printf("Digital Root: %d\n",n);
        printf("Number of Steps: %d",steps);
    }
    return 0;
}