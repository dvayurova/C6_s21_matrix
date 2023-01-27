#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;
  if (A->columns == B->rows) {
    if (correct_matrix(A) && correct_matrix(B)) {
      res = s21_create_matrix(A->rows, B->columns, result);
      if (res == OK) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < B->columns; j++) {
            for (int k = 0; k < B->rows; k++) {
              result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
            }
          }
        }
      }
    } else
      res = INCORRECT;
  } else
    res = CALC_ERROR;
  return res;
}