#include <stdio.h>
#include <string.h>
int count(char *str, char *find){
    int count = 0;
    char *temp = str;
    while((temp = strstr(temp,find))!=NULL){
        count++;
        temp+=strlen(find);
    }
    return count;
}
int main(){
    char str[1000];
    char find[100];
    fgets(str,sizeof(str),stdin);
    scanf("%s",find);
    printf("%d",count(str,find));
    return 0;
}