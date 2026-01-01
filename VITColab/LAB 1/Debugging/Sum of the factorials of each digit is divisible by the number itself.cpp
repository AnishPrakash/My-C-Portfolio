#include <stdio.h>
int main() {
    int start, end, num, found = 0;
    scanf("%d %d", &start, &end);
    for (num = start; num <= end; num++){
        int digit1 = num / 100;
        int digit2 = (num / 10) % 10;
        int digit3 = num%10;
        int fact1 = 1;
        for (int i = 1; i <= digit1; i++) {
            fact1 *= i;
        }
        int fact2 = 1;
        for (int j = 1; j <= digit2; j++) {
            fact2 *= j;
        }
        int fact3 = 1;
        for (int k = 1; k <= digit3; k++) {
            fact3 *= k;
        }
        int sumFactorials = fact1 + fact2 + fact3;
        if (sumFactorials % num == 0){
            printf("%d", num);
            found = 1;
        }
    }
    if(!found){
        printf("No elements");
    }
    return 0;
}