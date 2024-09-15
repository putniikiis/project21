#include <stdio.h>
#include <stdlib.h>

#define MAX_MATRIX_SIZE 100

void calculate_Cofactor(float originalMatrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE],
                        float temporary_matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE], int rowIndex,
                        int columnIndex, int matrixs_size) {
    int i = 0, j = 0;
    for (int row = 0; row < matrixs_size; row++) {
        for (int col = 0; col < matrixs_size; col++) {
            if (row != rowIndex && col != columnIndex) {
                temporary_matrix[i][j++] = originalMatrix[row][col];
                if (j == matrixs_size - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

float calculate_determinant(float matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE], int matrixs_size) {
    if (matrixs_size == 1) {
        return matrix[0][0];
    }

    float temporary_matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
    float determinant_value = 0;
    int sign = 1;

    for (int columnIndex = 0; columnIndex < matrixs_size; columnIndex++) {
        calculate_Cofactor(matrix, temporary_matrix, 0, columnIndex, matrixs_size);
        determinant_value +=
            sign * matrix[0][columnIndex] * calculate_determinant(temporary_matrix, matrixs_size - 1);
        sign = -sign;
    }

    return determinant_value;
}

int main() {
    int matrixs_size;
    float matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];

    if (scanf("%d %d", &matrixs_size, &matrixs_size) != 2 || matrixs_size <= 0) {
        printf("n/a");
        return 1;
    }

    for (int rowIndex = 0; rowIndex < matrixs_size; rowIndex++) {
        for (int columnIndex = 0; columnIndex < matrixs_size; columnIndex++) {
            if (scanf("%f", &matrix[rowIndex][columnIndex]) != 1) {
                printf("n/a");
                return 1;
            }
        }
    }

    float determinant_value = calculate_determinant(matrix, matrixs_size);

    printf("%.6f", determinant_value);

    return 0;
}