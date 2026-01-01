#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
    char str[100];
    char result[100];
    int vowel = 0;
    int j = 0;
    scanf("%[^\n]",str);
    for (int i = 0; str[i]!= '\0'; i++){
        char ch = tolower(str[i]);
        if (ch == 'a'|| ch=='e'||ch=='i'||ch=='o'||ch=='u'){
            vowel++;
        }
        else{
            result[j++] = str[i];
        }
    }
    result[j] = '\0';
    printf("Number of vowels: %d\n",vowel);
    printf("String after removing vowels: %s\n",result);
    return 0;
}