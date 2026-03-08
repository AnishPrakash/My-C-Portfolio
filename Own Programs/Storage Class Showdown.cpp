#include <stdio.h>

// Function 1: Using 'auto' (The default behavior)
void autoCounter() {
    // This variable is created FRESH every time the function is called.
    // When the function ends, this variable is destroyed (popped off the stack).
    int count = 0; 
    
    count++; // Increment
    printf("Auto Count: %d\n", count);
}

// Function 2: Using 'static' (The persistent behavior)
void staticCounter() {
    // This variable is created ONLY ONCE when the program starts.
    // It is NOT destroyed when the function ends. It remembers its value.
    static int count = 0; 
    
    count++; // Increment
    printf("Static Count: %d\n", count);
}

int main() {
    printf("--- Round 1: Auto Storage Class ---\n");
    autoCounter();
    autoCounter();
    autoCounter();

    printf("\n--- Round 2: Static Storage Class ---\n");
    staticCounter();
    staticCounter();
    staticCounter();

    return 0;
}