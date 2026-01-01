#include <stdio.h>
int main() {
    int weekday, month;
    scanf("%d%d", &weekday, &month);
    if (weekday < 1 || weekday > 7 || month < 1 || month > 12) {
        printf("Invalid Input");
        return 0;
    }
    switch(weekday) {
        case 1: printf("Sunday\n"); break;
        case 2: printf("Monday\n"); break;
        case 3: printf("Tuesday\n"); break;
        case 4: printf("Wednesday\n"); break;
        case 5: printf("Thursday\n"); break;
        case 6: printf("Friday\n"); break;
        case 7: printf("Saturday\n"); break;
    }
    if (month == 2) {
        printf("Either 28 or 29 Days in this Month");
    } 
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        printf("30 Days");
    } 
    else {
        printf("31 Days");
    }
    return 0;
}