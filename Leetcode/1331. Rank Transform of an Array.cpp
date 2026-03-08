#include <stdlib.h>

typedef struct {
    int val;
    int index;
} Elem;

int cmp1331(const void* a, const void* b) {
    return ((Elem*)a)->val - ((Elem*)b)->val;
}

int* arrayRankTransform(int* arr, int arrSize, int* returnSize) {
    if (arrSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    Elem* elems = (Elem*)malloc(arrSize * sizeof(Elem));
    for (int i = 0; i < arrSize; i++) {
        elems[i].val = arr[i];
        elems[i].index = i;
    }
    
    qsort(elems, arrSize, sizeof(Elem), cmp1331);
    
    int* res = (int*)malloc(arrSize * sizeof(int));
    int rank = 1;
    res[elems[0].index] = rank;
    
    for (int i = 1; i < arrSize; i++) {
        if (elems[i].val > elems[i-1].val) {
            rank++;
        }
        res[elems[i].index] = rank;
    }
    
    free(elems);
    *returnSize = arrSize;
    return res;
}