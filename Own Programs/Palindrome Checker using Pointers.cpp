#include <stdio.h>
#include <string.h>
int main() {
    char str[100];
    int isPalindrome = 1; 
    printf("Enter a string: ");
    scanf("%s", str);
    char *ptr_left = str; 
    char *ptr_right = str + strlen(str) - 1;
    while (ptr_left < ptr_right) {
        if (*ptr_left != *ptr_right) {
            isPalindrome = 0;
            break;
        }
        ptr_left++;
        ptr_right--;
    }
    if (isPalindrome == 1) {
        printf("'%s' is a Palindrome.\n", str);
    } else {
        printf("'%s' is NOT a Palindrome.\n", str);
    }
    return 0;
}