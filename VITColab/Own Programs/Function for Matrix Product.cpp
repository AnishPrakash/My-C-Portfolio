void matrixProduct(int matrix1[][10], int matrix2[][10], int resultMatrix[][10], int rows, int cols) {
    for (int i = 0; i<rows; i++){
        for (int j = 0; j<cols; j++){
            resultMatrix[i][j]=0;
            for (int k = 0; k<cols; k++){
                resultMatrix[i][j]+= matrix1[i][k]*matrix2[k][j];
            }
        }
    }
}

void displayMatrix(int matrix[][10], int rows, int cols) {
    for (int i = 0; i<rows; i++){
        for (int j = 0; j<cols; j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

