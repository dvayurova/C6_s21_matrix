#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = SUCCESS;
  if (equal_size(A, B) && correct_matrix(A) && correct_matrix(B)) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= 1e-7) res *= 0;
      }
    }
  } else
    res = FAILURE;
  return res;
}
