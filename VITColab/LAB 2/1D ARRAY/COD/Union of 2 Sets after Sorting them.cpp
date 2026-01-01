// You are using GCC
#include <stdio.h>
int main(){
    int T;
    scanf("%d",&T);
    int i = 0;
    while(i<T){
        int M ,N,count = 0;
        scanf("%d %d",&M,&N);
        int arr1[M];
        int arr2[N];
        for (int j = 0; j<M; j++){
            scanf("%d",&arr1[j]);
        }
        for (int j = 0; j<N; j++){
            scanf("%d",&arr2[j]);
        }
        for (int j = 0; j<M;j++){
            for (int k = j+1; k<M; k++){
                if(arr1[j]>arr1[k]){
                    int a = arr1[j];
                    arr1[j] = arr1[k];
                    arr1[k] = a;
                }
            }                     
        }                         
        for (int j = 0; j<N;j++){ 
            for (int k = j+1; k<N;k++){
                if(arr2[j]>arr2[k]){
                    int a = arr2[j];
                    arr2[j] = arr2[k];
                    arr2[k] = a;
                }
            }
        }
        for (int j = 0; j<M; j++){
            for (int k = 0;k<N;k++){
                if (arr1[j] == arr2[k]){
                    count++;
                    break;
                }
           }
        }
        int c = M+N-count;
        int final_arr[c];
        int a=0,b=0,p=0;
        while (a<M && b<N){
            if(arr1[a]<arr2[b]){
                final_arr[p++]=arr1[a++];
            }
            else if (arr1[a]>arr2[b]){
                final_arr[p++]=arr2[b++];
            }
            else{
                final_arr[p++] = arr1[a++];
                b++;
            }
        }
        while (a<M){
            final_arr[p++] = arr1[a++];
        }
        while (b<N){
            final_arr[p++] = arr2[b++];
        }
        for (int t = 0; t<c; t++){
            printf("%d ",final_arr[t]);
        }
        printf("\n");
        i++;
    }
    return 0;
}