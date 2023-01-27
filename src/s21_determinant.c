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
        *result = determ_three(A);
      } else {
      }
    } else
      res_code = INCORRECT;
  } else
    res_code = CALC_ERROR;
  return res_code;
}