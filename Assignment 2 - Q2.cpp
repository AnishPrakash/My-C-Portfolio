#include <stdio.h>
int main() {
    char type;
    int units;
    float total_amt;
    total_amt = 0.0;
    scanf("%c%d", &type,&units);
    if (type == 'D') {
        if (units <= 100) {
            total_amt = units * 1.0;
        } 
        else if (units <= 200) {
            total_amt = (100 * 1.0) + ((units - 100) * 2.50);
        } 
        else if (units <= 500) {
            total_amt = (100 * 1.0) + (100 * 2.50) + ((units - 200) * 4.0);
        } 
        else {
            total_amt = (100 * 1.0) + (100 * 2.50) + (300 * 4.0) + ((units - 500) * 6.0);
        }
        printf("Electricity Bill Amount: Rs. %.2f", total_amt);
    } 
    else if (type == 'C') {
        if (units <= 100) {
            total_amt = units * 2.0;
        } 
        else if (units <= 200) {
            total_amt = (100 * 2.0) + ((units - 100) * 4.50);
        } 
        else if (units <= 500) {
            total_amt = (100 * 2.0) + (100 * 4.50) + ((units - 200) * 6.0);
        } 
        else {
            total_amt = (100 * 2.0) + (100 * 4.50) + (300 * 6.0) + ((units - 500) * 7.0);
        }
        printf("Electricity Bill Amount: Rs. %.2f", total_amt);
    } 
    else {
        printf("Invalid type of EB connection. Please enter either D or C");
    }
    return 0;
}