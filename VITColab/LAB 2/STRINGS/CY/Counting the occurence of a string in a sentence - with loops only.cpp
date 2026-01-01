#include <stdio.h>
#include <string.h>
int main() {
    char str[1000];
    char find[100];
    int count = 0;
    fgets(str, sizeof(str), stdin);
    scanf("%s", find);
    int ls = strlen(str);
    int lf = strlen(find);
    for (int i = 0; i <= ls - lf; i++) {
        int match = 1;
        for (int j = 0; j < lf; j++) {
            if (str[i + j] != find[j]) {
                match = 0;
                break;
            }
        }
        if (match == 1) {
            count++; 
        }
    }
    printf("%d\n", count);
    return 0;
}