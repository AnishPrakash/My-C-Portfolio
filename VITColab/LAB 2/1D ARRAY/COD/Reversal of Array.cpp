// You are using GCC
#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    int rev[n];
    for (int i = 0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    
    int j = 0;
    for (int i = n-1; i>=0; i--){
        rev[j] = arr[i];
        j++;
    }
    for (int i = 0; i<n; i++){
        printf("%d ",rev[i]);
    }
    return 0;
}