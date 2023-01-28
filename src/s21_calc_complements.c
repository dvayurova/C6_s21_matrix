#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res_code = OK;
  matrix_t minor_matrix;
  double det = 0;
  if (A->columns == A->rows) {
    if (correct_matrix(A)) {
      res_code = s21_create_matrix(A->rows, A->columns, result);
      if (res_code == OK) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            det = 0;
            minor(A, &minor_matrix, i, j);
            s21_determinant(&minor_matrix, &det);
            result->matrix[i][j] = det * pow(-1, i + j);
          }
        }
      }
    } else
      res_code = INCORRECT;
  } else
    res_code = CALC_ERROR;
  return res_code;
}