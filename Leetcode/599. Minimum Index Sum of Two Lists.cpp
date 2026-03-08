#include <stdlib.h>
#include <string.h>
#include <limits.h>

char** findRestaurant(char** list1, int list1Size, char** list2, int list2Size, int* returnSize) {
    int minSum = INT_MAX;
    int count = 0;
    
    // First pass to find the minimum index sum
    for (int i = 0; i < list1Size; i++) {
        for (int j = 0; j < list2Size; j++) {
            if (strcmp(list1[i], list2[j]) == 0) {
                if (i + j < minSum) {
                    minSum = i + j;
                }
            }
        }
    }
    
    // Temporary array to hold potential matches (max size is min(list1Size, list2Size))
    char** tempRes = (char**)malloc((list1Size < list2Size ? list1Size : list2Size) * sizeof(char*));
    
    // Second pass to collect strings with the minimum index sum
    for (int i = 0; i < list1Size; i++) {
        for (int j = 0; j < list2Size; j++) {
            // Optimization: if index sum exceeds minSum, no need to strcmp
            if (i + j == minSum && strcmp(list1[i], list2[j]) == 0) {
                tempRes[count] = list1[i]; // No need to strdup, original strings persist
                count++;
            }
        }
    }
    
    *returnSize = count;
    return tempRes;
}