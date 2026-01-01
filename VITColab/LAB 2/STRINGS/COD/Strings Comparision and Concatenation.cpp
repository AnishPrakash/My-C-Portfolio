#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
    char str1[50],str2[50],copy[50];
    scanf("%[^ ]%*c",&str1);
    scanf("%[^ ]%*c",&str2);
    strcpy(copy,str1);
    int a = strcmp(str1,str2);
    strcat(str1,str2);
    printf("Copied: %s\n",copy);
    if (a!=0){
        printf("Comparison: Not Equal\n");
    }
    else{
        printf("Comparison: Equal\n");
    }
    printf("Concatenated: %s\n",str1);
    return 0;
}
