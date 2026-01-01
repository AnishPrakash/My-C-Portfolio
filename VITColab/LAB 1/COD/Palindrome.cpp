#include <stdio.h>
int len(int num);
int main(){
    int num;
    scanf("%d",&num);
    int l = len(num);
    int arr[l];
    int a[l];
    int count = 0;
    for (int j = 0; j<l; j++){
        int r = num%10;
        arr[j] = r;
        num = num/10;
    }
    for (int k = 0; k<l; k++){
        a[k] = arr[l-1-k];
    }
    for (int m = 0; m<l; m++){
        if (a[m] == arr[m]){
            count++;
        }
        else{
            continue;
        }
    }
    if (count == l){
        for (int p = 0; p<l; p++){
            printf("%d",arr[p]);
        }
        printf("\nPalindrome");
    }
    else{
        for (int p = 0; p<l; p++){
            printf("%d",arr[p]);
        }
        printf("\nNot Palindrome");
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
