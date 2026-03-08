#include <stdio.h>
int main(){
    int rows,cols;
    scanf("%d %d", &rows, &cols);
    int arr[rows][cols];
    int borderSum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d",&arr[i][j]);
        }
    }
    for (int i = 0; i < rows; i++) {
        borderSum += arr[i][0];
        if (cols>1){
            borderSum += arr[i][cols-1];
        }
    }
    for (int j = 1; j < cols - 1; j++) {
        borderSum += arr[0][j];
        if (rows>1){
            borderSum += arr[rows - 1][j];
        }
    }
    printf("%d\n", borderSum);
    int sumOfDigits = 0;
    int temp = borderSum;
    while (temp > 0) {
        sumOfDigits += temp % 10;
        temp /= 10;
    }
    printf("%d\n", sumOfDigits);
    return 0;
}