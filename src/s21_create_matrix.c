#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int res = OK, stop = 0;
  if (result == NULL) {
    res = INCORRECT;
  } else if (rows >= 1 && columns >= 1) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double *));
    if (result->matrix != NULL) {
      for (int i = 0; i < rows && !stop; i++) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
        if (result->matrix[i] == NULL) {
          stop = 1;
          for (int j = 0; j <= i; j++) free(result->matrix[j]);
        }
      }
    }
    if (stop == 1 || result->matrix == NULL) {
      res = INCORRECT;
      free(result->matrix);
      result->matrix = NULL;
    }
  } else {
    res = INCORRECT;
    result->matrix = NULL;
  }
  return res;
}