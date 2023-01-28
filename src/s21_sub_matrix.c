#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;
  if (correct_matrix(A) && correct_matrix(B)) {
    if (equal_size(A, B)) {
      res = s21_create_matrix(A->rows, A->columns, result);
      if (res == OK) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
          }
        }
      }
    } else
      res = CALC_ERROR;
  } else
    res = INCORRECT;
  return res;
}