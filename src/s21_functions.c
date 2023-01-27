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

void minor(matrix_t *A, matrix_t *minor, int x, int y) {
  if (correct_matrix(A)) {
    if (s21_create_matrix(A->rows - 1, A->columns - 1, minor) == OK) {
      for (int i = 0, m = 0; i < A->rows; i++, m++) {
        for (int j = 0, n = 0; j < A->columns; j++, n++) {
          if (i != x && j != y) minor->matrix[m][n] = A->matrix[i][j];
          if (j == y) n--;
        }
        if (i == x) m--;
      }
    }
  }
}

double determ_two(matrix_t *A) {
  return A->matrix[0][0] * A->matrix[1][1] - A->matrix[1][0] * A->matrix[0][1];
}

double determ_three(matrix_t *A) {
  double det = 0;
  matrix_t temp_matrix;
  for (int i = 0; i < 3; i++) {
    minor(A, &temp_matrix, 0, i);
    det += determ_for_two(&temp_matrix) * (i % 2 == 0 ? 1 : -1);
  }
}