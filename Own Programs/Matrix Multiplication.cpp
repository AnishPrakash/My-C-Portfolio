#include <stdio.h>
int main() {
    int r1, c1, r2, c2;
    printf("Enter rows and columns for Matrix 1: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns for Matrix 2: ");
    scanf("%d %d", &r2, &c2);
    if (c1 != r2) {
        printf("Error: Matrix multiplication not possible.\n");
        printf("Columns of Matrix 1 (%d) must equal Rows of Matrix 2 (%d).\n", c1, r2);
        return 1;
    }
    int arr1[r1][c1];
    int arr2[r2][c2];
    int result[r1][c2];
    printf("Enter elements for Matrix 1 (%dx%d):\n", r1, c1);
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d", &arr1[i][j]);
        }
    }
    printf("Enter elements for Matrix 2 (%dx%d):\n", r2, c2);
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            scanf("%d", &arr2[i][j]);
        }
    }
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
        }
    }
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    printf("Resultant Matrix (%dx%d):\n", r1, c2);
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}
