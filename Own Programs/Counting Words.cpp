#include <stdio.h>
int main() {
    char a[100];
    printf("Enter your string: ");
    scanf("%[^\n]%*c", a); 
    int count = 0;
    int i = 0;
    int inWord = 0; 
    while (a[i] != '\0') {
        if (a[i] != ' ') {
            if (inWord == 0) {
                count++;
                inWord = 1;
            }
        } 
        else {
            inWord = 0;
        }
        i++;
    }
    printf("Word count is %d.", count);
    return 0;
}