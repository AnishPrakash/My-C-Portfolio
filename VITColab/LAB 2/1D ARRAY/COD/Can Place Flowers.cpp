// You are using GCC
#include <stdio.h>
int main(){
    int T,N;
    scanf("%d",&T);
    int i = 0;
    while(i<T){
        int t=0;
        scanf("%d",&N);
        int arr[N];
        for (int j = 0; j<N; j++){
            scanf("%d",&arr[j]);
        }
        for (int j = 0; j<N; j++){
            if (arr[j] == 1){
                continue;
            }
            int left = (j==0) ? 0 : arr[j-1];
            int right = (j==N-1)? 0 : arr[j+1];
            if (left == 0&&right == 0){
                arr[j] = 1;
                t++;
            }
        }
        printf("%d\n",t);
        i++;
    }
    return 0;
}