// You are using GCC
#include <stdio.h>
#include <string.h>
int main() {
    char str1[25];
    char str2[25];
    char result[50];
    scanf("%s",&str1);
    scanf("%s",&str2);
    strcpy(result, str1);
    strcat(result, " ");
    strcat(result, str2);
    printf("%s\n", result);
    return 0;
}