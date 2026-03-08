#include <stdio.h>
#include <stdlib.h>
int compareDesc(const void *a, const void *b) {
    return (*(const int *)b) - (*(const int *)a);
}
void merge(int * p1, int * p2, int s1, int s2) {
    int * a3 = (int*)malloc((s1+s2)*sizeof(int));
    int i = 0, j = 0;
    int k = 0;
    while(i < s1 && j < s2) {
        if (*(p1+i) > *(p2+j)) {
            *(a3+k) = *(p1+i);
            i++;
        } else {
            *(a3+k) = *(p2+j);
            j++;
        }
        k++;
    }
    while(i < s1) {
        *(a3+k) = *(p1+i);
        i++;
        k++;
    }
    while(j < s2) {
        *(a3+k) = *(p2+j);
        j++;
        k++;
    }
    printf("Merged Array: ");
    for(int i = 0; i < s1+s2; i++) {
        if (i > 0) printf(" ");
        printf("%d", *(a3+i));
    }
    printf("\n");
    free(a3);
}
int main() {
    int n1, n2;
    printf("Provide size for both the arrays!\n");
    scanf("%d %d", &n1, &n2);
    int * a1 = (int*)malloc(n1*sizeof(int));
    int * a2 = (int*)malloc(n2*sizeof(int));
    printf("Enter elements for array 1:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", a1+i);
    }
    printf("Enter elements for array 2:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", a2+i);
    }
    qsort(a1, n1, sizeof(int), compareDesc);
    qsort(a2, n2, sizeof(int), compareDesc);
    merge(a1, a2, n1, n2);
    free(a1);
    free(a2);
    return 0;
}