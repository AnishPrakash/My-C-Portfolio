#include <stdio.h>
int len(int num);
int main(){
    int l,n,count = 0,b,r;
    scanf("%d",&n);
    l = len(n);
    int arr[l];
    int a[l];
    for (int i = 0; i<l; i++){
        r = n%10;
        arr[i] = r;
        n/=10;
    }
    for (int k = 0; k<l; k++){
        a[k] = arr[l-k-1];
    }
    for (int m = l-1; m>0 ;m--){
        for(int p = m-1;p>=0;p--){
            if (a[m] == a[p]){
                b = m;
                count++;
                break;
            }
        }
        if (count!=0){
            break;
        }
    }
    if (count == 0 ){
        printf("No repeated digits found.");
    }
    else{
        printf("First repeated digit: %d",a[b]);
    }
    return 0;
}
int len(int num){
    int l = 0;
    while (num!=0){
        num/=10;
        l++;
    }
    return l;
}