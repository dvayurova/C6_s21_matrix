#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int res_code = OK;
  if (A->columns == A->rows) {
    if (correct_matrix(A)) {
      if (A->rows == 1) {
        *result = A->matrix[0][0];
      } else if (A->rows == 2) {
        *result = determ_for_two(A);
      } else if (A->rows == 3) {
        det = A->matrix[0][0] *
      } else {
      }
    } else
      res = INCORRECT;
  } else
    res = CALC_ERROR;
  return res_code;
}