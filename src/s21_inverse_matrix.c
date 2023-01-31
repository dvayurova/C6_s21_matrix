#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int res_code = OK;
  matrix_t matrix_calc = {0};
  matrix_t matrix_trns = {0};
  double det = 0;
  if (correct_matrix(A)) {
    if (A->columns == A->rows) {
      s21_determinant(A, &det);
      if (fabs(det) >= 1e-7) {
        if (A->columns == 1) {
          res_code = s21_create_matrix(A->rows, A->columns, result);
          result->matrix[0][0] = 1.0 / det;
        } else {
          res_code = s21_calc_complements(A, &matrix_calc);
          res_code = s21_transpose(&matrix_calc, &matrix_trns);
          res_code = s21_mult_number(&matrix_trns, 1.0 / det, result);
        }
      } else
        res_code = CALC_ERROR;
    } else
      res_code = CALC_ERROR;
  } else
    res_code = INCORRECT;
  s21_remove_matrix(&matrix_calc);
  s21_remove_matrix(&matrix_trns);
  return res_code;
}