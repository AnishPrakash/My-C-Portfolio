#include <stdio.h>
int main(){
    int T,I=0;
    scanf("%d",&T);
    while(I<T){
        int N;
        scanf("%d",&N);
        int arr[N];
        for(int i = 0; i<N;i++){
            scanf("%d",&arr[i]);
        }
        int max_index = -1;
        if (N==1){
            max_index = 1;
        }
        else if (N==2){
            if(arr[1]>=arr[0]){
                max_index = 2;
            }
            else{
                max_index = 1;
            }
        }
        else{
            int current_max = -99999;
            for (int i = 1; i<N;i++){
                int increase = arr[i]-arr[i-1];
                if (increase>current_max){
                    current_max = increase;
                    max_index = i+1;
                }
            }
        }
        printf("%d\n",max_index);
        I++;
    }
    return 0;
}