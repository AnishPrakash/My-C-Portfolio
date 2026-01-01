// You are using GCC
#include <stdio.h>
int main(){
    int T;
    char b[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    scanf("%d",&T);
    int I = 0;
    while(I<T){
        int num;
        scanf("%d",&num);
        int a[num];
        for (int i = 0; i<num;i++){
            scanf("%d",&a[i]);
        }
        char answer[num];
        for (int i = 0; i<num;i++){
            int x = 0;
            x = a[i];
            x-=1;
            answer[i] = b[x];
        }
        for (int i = 0; i<num; i++){
            printf("%c",answer[i]);
        }
        printf("\n");
        I++;
    }
    return 0;
}