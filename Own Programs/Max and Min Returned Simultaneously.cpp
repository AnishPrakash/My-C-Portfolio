#include <stdio.h>
// Function accepts the array, size, AND pointers to where the results should go
void findMaxMin(int *arr, int size, int *max, int *min){
    // 1. Initialize logic: Start by assuming the first element is both max and min
    // NOTE: We use *max to change the value AT the address
    *max = arr[0];
    *min = arr[0];

    for (int i = 1; i < size; i++) {
        // Check for new Max
        if (arr[i] > *max) {
            *max = arr[i]; // Update the value at the 'max' address
        }
        // Check for new Min
        if (arr[i] < *min) {
            *min = arr[i]; // Update the value at the 'min' address
        }
    }
    // No return needed! We already updated the variables in main() directly.
}
int main() {
    int arr[5] = {10, 50, 2, 80, 15};
    int max, min; // We declare variables to hold the results
    // We pass the ADDRESS (&) of max and min so the function can fill them
    findMaxMin(arr, 5, &max, &min);
    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);
    return 0;
}