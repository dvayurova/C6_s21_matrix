#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int res_code = OK;
  double temp_det = 0;
  matrix_t temp_matrix = {0};
  *result = 0;
  if (correct_matrix(A)) {
    if (A->columns == A->rows) {
      if (A->rows == 1) {
        *result = A->matrix[0][0];
      } else if (A->rows == 2) {
        *result = determ_two(A);
      } else {
        for (int i = 0; i < A->rows; i++) {
          temp_det = 0;
          if (s21_create_matrix(A->rows - 1, A->columns - 1, &temp_matrix) ==
              OK) {
            minor_matr(A, &temp_matrix, i, 0);
            res_code = s21_determinant(&temp_matrix, &temp_det);
            *result =
                *result + A->matrix[i][0] * temp_det * (i % 2 == 0 ? 1 : -1);
            s21_remove_matrix(&temp_matrix);
          } else
            res_code = INCORRECT;
        }
      }
    } else
      res_code = CALC_ERROR;
  } else
    res_code = INCORRECT;
  return res_code;
}