// You are using GCC
#include <stdio.h>
int main(){
    int T;
    scanf("%d",&T);
    int I = 0;
    while (I<T){
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i = 0; i<n; i++){
            scanf("%d",&arr[i]);
        }
        int arr1[n];
        int b=0;
        for (int i = 0; i<n; i++){
            int found = 0;
            for (int j = 0; j<b; j++){
                if (arr[i] == arr1[j]){
                    found = 1;
                    break;
                }
            }
            if (found == 0){
                arr1[b] = arr[i];
                b++;
            }
        }
        for (int k = 0; k<b; k++){
            printf("%d ",arr1[k]);
        }
        printf("\n");
        I++;
    }
    return 0;
}