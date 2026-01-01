#include <stdio.h>
#include <string.h>
int main() {
    char str[500];
    scanf("%s", str);
    int l = strlen(str);
    for (int i = 0; i < l; i++) {
        int count = 1;
        while (i < l - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }
        printf("%c%d", str[i], count);
    }
    return 0;
}