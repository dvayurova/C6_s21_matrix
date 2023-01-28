#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int res_code = OK;
  matrix_t matrix_calc;
  matrix_t matrix_trns;
  double det = 0;
  if (A->columns == A->rows) {
    if (correct_matrix(A)) {
      res_code = s21_determinant(A, &det);
      if (res_code == OK && fabs(det) > 1e-7) {
        res_code = s21_create_matrix(A->rows, A->columns, result);
        if (res_code == OK) {
          s21_calc_complements(A, &matrix_calc);
          s21_transpose(&matrix_calc, &matrix_trns);
          s21_mult_number(&matrix_trns, 1.0 / det, result);
        }
      }
    } else
      res_code = INCORRECT;
  } else
    res_code = CALC_ERROR;
  return res_code;
}