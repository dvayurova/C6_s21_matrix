#include "s21_matrix.h"

int correct_matrix(matrix_t *A) {
  int res = FAILURE;
  if (A->rows >= 1 && A->columns >= 1 && A->matrix != NULL) {
    for (int i = 0; i < A->rows; i++) {
      if (A->matrix[i] != NULL)
        res = SUCCESS;
      else
        res = FAILURE;
    }
  }
  return res;
}

int equal_size(matrix_t *A, matrix_t *B) {
  int res = FAILURE;
  if (A->rows == B->rows && A->columns == B->columns) res = SUCCESS;
  return res;
}