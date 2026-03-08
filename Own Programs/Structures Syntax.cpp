#include <stdio.h>
#include <string.h>

// Definition
struct Student {
    int id;           // 4 bytes
    char name[20];    // 20 bytes
    float percentage; // 4 bytes
};

int main() {
    // Declaration
    struct Student s1;

    // Initialization
    s1.id = 101;
    strcpy(s1.name, "John Doe");
    s1.percentage = 92.5;

    // Accessing members
    printf("ID: %d, Name: %s, Percentage: %.2f\n", s1.id, s1.name, s1.percentage);

    return 0;
}