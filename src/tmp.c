#include <stdio.h>

#include "s21_matrix.h"

int main() {
  int rows1 = 3;
  int columns1 = 4;
  matrix_t matrixA;
  matrix_t matrixB;
  matrix_t result;
  printf("\n create A = %d \n", s21_create_matrix(rows1, columns1, &matrixA));
  matrixA.matrix[0][0] = 1;
  matrixA.matrix[1][0] = 2;
  matrixA.matrix[2][0] = 3;
  matrixA.matrix[0][1] = 4;
  matrixA.matrix[1][1] = 5;
  matrixA.matrix[2][1] = 6;
  matrixA.matrix[0][2] = 7;
  matrixA.matrix[1][2] = 8;
  matrixA.matrix[2][2] = 9;
  matrixA.matrix[0][3] = -5;
  matrixA.matrix[1][3] = 0;
  matrixA.matrix[2][3] = -10;
  for (int i = 0; i < rows1; i++) {
    for (int j = 0; j < columns1; j++) {
      printf("%f\t", matrixA.matrix[i][j]);
    }
    printf("\n");
  }

  int rows2 = 3;
  int columns2 = 5;
  printf("\n create B = %d \n", s21_create_matrix(rows2, columns2, &matrixB));
  matrixB.matrix[0][0] = 1;
  matrixB.matrix[0][1] = -1;
  matrixB.matrix[0][2] = 1;
  matrixB.matrix[0][3] = 2;
  matrixB.matrix[0][4] = -9;
  matrixB.matrix[1][0] = 2;
  matrixB.matrix[1][1] = 3;
  matrixB.matrix[1][2] = 4;
  matrixB.matrix[1][3] = 5;
  matrixB.matrix[1][4] = 6;
  matrixB.matrix[2][0] = 0;
  matrixB.matrix[2][1] = 0;
  matrixB.matrix[2][2] = 0;
  matrixB.matrix[2][3] = 0;
  matrixB.matrix[2][4] = 0;
  // matrixB.matrix[3][0] = 5;
  // matrixB.matrix[3][1] = 5;
  // matrixB.matrix[3][2] = -5;
  // matrixB.matrix[3][3] = -5;
  // matrixB.matrix[3][4] = -5;

  // for (int i = 0; i < rows2; i++) {
  //   for (int j = 0; j < columns2; j++) {
  //     printf("%f\t", matrixB.matrix[i][j]);
  //   }
  //   printf("\n");
  // }
  // matrixB.matrix[2][2] = 55;
  // matrixA.matrix[2] = NULL;
  printf("\n s21_eq_matrix = %d", s21_eq_matrix(&matrixA, &matrixB));
  printf("\n s21_mult_matrix = %d\n",
         s21_mult_matrix(&matrixA, &matrixB, &result));
  // for (int i = 0; i < rows1; i++) {
  //   for (int j = 0; j < columns2; j++) {
  //     printf("%f ", result.matrix[i][j]);
  //   }
  //   printf("\n");
  // }

  printf("\n s21_transpose = %d \n", s21_transpose(&matrixA, &result));
  for (int i = 0; i < columns1; i++) {
    for (int j = 0; j < rows1; j++) {
      printf("%f ", result.matrix[i][j]);
    }
    printf("\n");
  }
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
  return 0;
}