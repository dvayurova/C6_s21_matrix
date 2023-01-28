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
  if (A->rows == B->rows && A->columns == B->columns)
    res = SUCCESS;
  return res;
}

int minor(matrix_t *A, matrix_t *minor, int x, int y) {
  int res = OK;
  if (correct_matrix(A)) {
    if ((res = s21_create_matrix(A->rows - 1, A->columns - 1, minor)) == OK) {
      for (int i = 0, m = 0; i < A->rows; i++, m++) {
        for (int j = 0, n = 0; j < A->columns; j++, n++) {
          if (i != x && j != y)
            minor->matrix[m][n] = A->matrix[i][j];
          if (j == y)
            n--;
        }
        if (i == x)
          m--;
      }
    }
  } else
    res = INCORRECT;
  return res;
}

double determ_two(matrix_t *A) {
  return A->matrix[0][0] * A->matrix[1][1] - A->matrix[1][0] * A->matrix[0][1];
}
