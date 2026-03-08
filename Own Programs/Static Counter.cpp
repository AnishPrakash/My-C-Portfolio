#include <stdio.h>
void transaction(int amount) {
    // 'static' means this variable is initialized ONLY ONCE.
    // It is NOT destroyed when the function ends.
    static int balance = 0; 
    balance = balance + amount;    
    printf("Deposit: %d \t| Current Balance: %d\n", amount, balance);
}
int main() {
    transaction(100);
    transaction(50);
    transaction(200);
    return 0;
}