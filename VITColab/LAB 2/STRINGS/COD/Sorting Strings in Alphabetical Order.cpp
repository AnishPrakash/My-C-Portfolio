#include <stdio.h>
#include <string.h>
int main(){
    int n;
    scanf("%d",&n);
    char keywords[n][100];
    for (int i = 0; i<n; i++){
        scanf("%s", keywords[i]);
    }
    for (int i = 0; i<n-1; i++){
        for (int j = 0; j<n-i-1; j++){
            if (strcmp(keywords[j],keywords[j+1])>0){
                char temp[100];
                strcpy(temp,keywords[j]);
                strcpy(keywords[j],keywords[j+1]);
                strcpy(keywords[j+1],temp);
            }
        }
    }
    for (int i = 0; i<n; i++){
        printf("%s%s",keywords[i],(i==n-1)?"":" ");
    }
    printf("\n");
    return 0;
}