#include <stdio.h>

#include "s21_matrix.h"

int main() {
  int rows1 = 3;
  int columns1 = 4;
  matrix_t matrixA;
  matrix_t matrixB;
  matrix_t result;
  printf("\n create A = %d \n", s21_create_matrix(rows1, columns1, &matrixA));
  for (int i = 0; i < rows1; i++) {
    for (int j = 0; j < columns1; j++) {
      matrixA.matrix[i][j] = 1.0 + j;
      printf("%f ", matrixA.matrix[i][j]);
    }
    printf("\n");
  }

  int rows2 = -3;
  int columns2 = 4;
  printf("\n create B = %d \n", s21_create_matrix(rows2, columns2, &matrixB));
  // for (int i = 0; i < rows2; i++) {
  //   for (int j = 0; j < columns2; j++) {
  //     matrixB.matrix[i][j] = 0 + j;
  //     printf("%f ", matrixB.matrix[i][j]);
  //   }
  //   printf("\n");
  // }
  // matrixB.matrix[2][2] = 55;
  // matrixA.matrix[2] = NULL;
  printf("\n s21_eq_matrix = %d", s21_eq_matrix(&matrixA, &matrixB));
  printf("\n s21_sum_matrix = %d\n",
         s21_sum_matrix(&matrixA, &matrixB, &result));
  // for (int i = 0; i < rows2; i++) {
  //   for (int j = 0; j < columns2; j++) {
  //     printf("%f ", result.matrix[i][j]);
  //   }
  //   printf("\n");
  // }
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
  return 0;
}