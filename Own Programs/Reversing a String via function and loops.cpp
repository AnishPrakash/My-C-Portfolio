#include <stdio.h>
#include <string.h>
void reverseString(char str[]){
    int len = strlen(str);
    for (int i = 0; i < len/2; i++) {
        char temp = str[i];
        str[i] = str[len - i-1];
        str[len - i-1] = temp;
    }
    printf("%s\n",str);
}

int main(){
    char input[50];
    fgets(input, sizeof(input), stdin);
    reverseString(input);
    return 0;
}