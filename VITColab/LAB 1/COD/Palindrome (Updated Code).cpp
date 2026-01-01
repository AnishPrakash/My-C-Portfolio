#include <stdio.h>
int len(int num);
int main(){
    int num;
    scanf("%d",&num);
    int l = len(num);
    int arr[l];
    int count = 0;
    for (int j = 0; j<l; j++){
        int r = num%10;
        arr[j] = r;
        num = num/10;
    }
    for (int m = 0; m<l; m++){
        if (arr[m] == arr[l-m-1]){
            count++;
        }
    }
    for (int p = 0; p<l; p++){
		printf("%d",arr[p]);
    }
    if (count == l){
        printf("\nPalindrome");
    }
    else{
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
