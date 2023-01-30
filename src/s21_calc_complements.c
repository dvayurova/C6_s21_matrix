#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res_code = OK;
  matrix_t minor_matrix = {0};
  double det = 0;
  if (correct_matrix(A)) {
    if (A->columns == A->rows && A->rows > 1) {
      res_code = s21_create_matrix(A->rows, A->columns, result);
      if (res_code == OK) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            det = 0;
            if (s21_create_matrix(A->rows - 1, A->columns - 1, &minor_matrix) ==
                OK) {
              minor_matr(A, &minor_matrix, i, j);
              s21_determinant(&minor_matrix, &det);
              result->matrix[i][j] = det * pow(-1, i + j);
              s21_remove_matrix(&minor_matrix);
            } else {
              s21_remove_matrix(result);
              res_code = INCORRECT;
            }
          }
        }
      }
    } else
      res_code = CALC_ERROR;
  } else
    res_code = INCORRECT;
  return res_code;
}