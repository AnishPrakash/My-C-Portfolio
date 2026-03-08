#include <stdio.h>
int main(){
    int n,i,j,sum = 0;
    printf("Enter the size of the square matrix (N): ");
    scanf("%d", &n);
    int matrix[n][n];
    printf("Enter the elements of the %dx%d matrix:\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("\nSum of diagonal (");   
    for (i = 0; i < n; i++) {
        sum = sum + matrix[i][i];
        printf("%d", matrix[i][i]);
        if (i < n - 1) {
            printf("+");
        }
    }
    printf("): %d\n", sum);
    return 0;
}