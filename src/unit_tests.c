#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_matrix.h"

START_TEST(create_correct) {
  matrix_t matrixA;
  int rows = 3;
  int columns = 5;
  ck_assert_int_eq(0, s21_create_matrix(rows, columns, &matrixA));
  ck_assert_int_eq(rows, matrixA.rows);
  ck_assert_int_eq(columns, matrixA.columns);
  s21_remove_matrix(&matrixA);
}
END_TEST

START_TEST(create_correct2) {
  matrix_t matrixA = {0};
  int rows = 3;
  int columns = 5;
  ck_assert_int_eq(0, s21_create_matrix(rows, columns, &matrixA));
  s21_remove_matrix(&matrixA);
}
END_TEST

START_TEST(create_incorrect1) {
  matrix_t matrixA;
  int rows = -3;
  int columns = 5;
  ck_assert_int_eq(1, s21_create_matrix(rows, columns, &matrixA));
  s21_remove_matrix(&matrixA);
}
END_TEST

START_TEST(create_incorrect2) {
  matrix_t matrixA;
  int rows = 0;
  int columns = 0;
  ck_assert_int_eq(1, s21_create_matrix(rows, columns, &matrixA));
  s21_remove_matrix(&matrixA);
}
END_TEST

START_TEST(create_incorrect3) {
  matrix_t *matrixA = NULL;
  int rows = 2;
  int columns = 3;
  ck_assert_int_eq(1, s21_create_matrix(rows, columns, matrixA));
}
END_TEST

START_TEST(eq_matrix_incorrect) {
  matrix_t matrixA;
  matrix_t matrixB;
  int rows_A = 0, columns_A = 0;
  int rows_B = 1, columns_B = -2;
  s21_create_matrix(rows_A, columns_A, &matrixA);
  s21_create_matrix(rows_B, columns_B, &matrixB);
  ck_assert_int_eq(0, s21_eq_matrix(&matrixA, &matrixB));
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
}
END_TEST

START_TEST(eq_matrix_eq) {
  matrix_t matrixA;
  matrix_t matrixB;
  int rows_A = 6, columns_A = 6;
  int rows_B = 6, columns_B = 6;
  int k = 1;
  s21_create_matrix(rows_A, columns_A, &matrixA);
  s21_create_matrix(rows_B, columns_B, &matrixB);
  for (int i = 0; i < rows_A; i++) {
    for (int j = 0; j < columns_A; j++) {
      matrixA.matrix[i][j] = k;
      k++;
    }
  }
  k = 1;
  for (int i = 0; i < rows_B; i++) {
    for (int j = 0; j < columns_B; j++) {
      matrixB.matrix[i][j] = k;
      k++;
    }
  }
  ck_assert_int_eq(1, s21_eq_matrix(&matrixA, &matrixB));
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
}
END_TEST

START_TEST(eq_matrix_eq2) {
  matrix_t matrixA;
  matrix_t matrixB;
  int rows_A = 4, columns_A = 4;
  int rows_B = 4, columns_B = 4;
  double k = -56.987654321;
  s21_create_matrix(rows_A, columns_A, &matrixA);
  s21_create_matrix(rows_B, columns_B, &matrixB);
  for (int i = 0; i < rows_A; i++) {
    for (int j = 0; j < columns_A; j++) {
      matrixA.matrix[i][j] = k;
      k++;
    }
  }
  k = -56.987654321;
  for (int i = 0; i < rows_B; i++) {
    for (int j = 0; j < columns_B; j++) {
      matrixB.matrix[i][j] = k;
      k++;
    }
  }
  ck_assert_int_eq(1, s21_eq_matrix(&matrixA, &matrixB));
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
}
END_TEST

START_TEST(eq_matrix_eq3) {
  matrix_t matrixA;
  matrix_t matrixB;
  int rows_A = 4, columns_A = 4;
  int rows_B = 4, columns_B = 4;
  double k = -56.987654321;
  s21_create_matrix(rows_A, columns_A, &matrixA);
  s21_create_matrix(rows_B, columns_B, &matrixB);
  for (int i = 0; i < rows_A; i++) {
    for (int j = 0; j < columns_A; j++) {
      matrixA.matrix[i][j] = k;
      k++;
    }
  }
  k = -56.987654331;
  for (int i = 0; i < rows_B; i++) {
    for (int j = 0; j < columns_B; j++) {
      matrixB.matrix[i][j] = k;
      k++;
    }
  }
  ck_assert_int_eq(1, s21_eq_matrix(&matrixA, &matrixB));
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
}
END_TEST

START_TEST(eq_matrix_eq4) {
  matrix_t matrixA;
  matrix_t matrixB;
  int rows_A = 3, columns_A = 3;
  int rows_B = 3, columns_B = 3;
  double k = -56.987654321;
  s21_create_matrix(rows_A, columns_A, &matrixA);
  s21_create_matrix(rows_B, columns_B, &matrixB);
  for (int i = 0; i < rows_A; i++) {
    for (int j = 0; j < columns_A; j++) {
      matrixA.matrix[i][j] = k;
      k++;
    }
  }
  k = -56.987654321;
  for (int i = 0; i < rows_B; i++) {
    for (int j = 0; j < columns_B; j++) {
      matrixB.matrix[i][j] = k;
      k++;
    }
  }
  matrixB.matrix[2][2] = 0;
  ck_assert_int_eq(0, s21_eq_matrix(&matrixA, &matrixB));
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
}
END_TEST

START_TEST(eq_matrix_not_eq1) {
  matrix_t matrixA;
  matrix_t matrixB;
  int rows_A = 6, columns_A = 6;
  int rows_B = 6, columns_B = 6;
  int k = 1;
  s21_create_matrix(rows_A, columns_A, &matrixA);
  s21_create_matrix(rows_B, columns_B, &matrixB);
  for (int i = 0; i < rows_A; i++) {
    for (int j = 0; j < columns_A; j++) {
      matrixA.matrix[i][j] = k;
      k++;
    }
  }
  for (int i = 0; i < rows_B; i++) {
    for (int j = 0; j < columns_B; j++) {
      matrixB.matrix[i][j] = k;
      k++;
    }
  }
  ck_assert_int_eq(0, s21_eq_matrix(&matrixA, &matrixB));
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
}
END_TEST

START_TEST(eq_matrix_not_eq2) {
  matrix_t matrixA;
  matrix_t matrixB;
  int rows_A = 5, columns_A = 3;
  int rows_B = 6, columns_B = 6;
  int k = 1;
  s21_create_matrix(rows_A, columns_A, &matrixA);
  s21_create_matrix(rows_B, columns_B, &matrixB);
  for (int i = 0; i < rows_A; i++) {
    for (int j = 0; j < columns_A; j++) {
      matrixA.matrix[i][j] = k;
      k++;
    }
  }
  k = 1;
  for (int i = 0; i < rows_B; i++) {
    for (int j = 0; j < columns_B; j++) {
      matrixB.matrix[i][j] = k;
      k++;
    }
  }
  ck_assert_int_eq(0, s21_eq_matrix(&matrixA, &matrixB));
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
}
END_TEST

START_TEST(sum_correct1) {
  matrix_t matrixA;
  matrix_t matrixB;
  matrix_t result;
  matrix_t correct_result;
  int rows_A = 2, columns_A = 3;
  int rows_B = 2, columns_B = 3;
  double k = 1.1234567;
  s21_create_matrix(rows_A, columns_A, &matrixA);
  s21_create_matrix(rows_B, columns_B, &matrixB);
  s21_create_matrix(rows_B, columns_B, &correct_result);
  for (int i = 0; i < rows_A; i++) {
    for (int j = 0; j < columns_A; j++) {
      matrixA.matrix[i][j] = k;
      k++;
    }
  }
  k = 1.1234567;
  for (int i = 0; i < rows_B; i++) {
    for (int j = 0; j < columns_B; j++) {
      matrixB.matrix[i][j] = k;
      k++;
    }
  }
  k = 1.1234567;
  for (int i = 0; i < rows_B; i++) {
    for (int j = 0; j < columns_B; j++) {
      correct_result.matrix[i][j] = k * 2;
      k++;
    }
  }
  ck_assert_int_eq(0, s21_sum_matrix(&matrixA, &matrixB, &result));
  for (int i = 0; i < rows_B; i++) {
    for (int j = 0; j < columns_B; j++) {
      ck_assert_ldouble_eq_tol(correct_result.matrix[i][j], result.matrix[i][j],
                               1e-7);
    }
  }
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct_result);
}
END_TEST

START_TEST(sum_correct2) {
  matrix_t matrixA;
  matrix_t matrixB;
  matrix_t result;
  matrix_t correct_result;
  int rows_A = 4, columns_A = 4;
  int rows_B = 4, columns_B = 4;
  double k = -56.987654321;
  s21_create_matrix(rows_A, columns_A, &matrixA);
  s21_create_matrix(rows_B, columns_B, &matrixB);
  s21_create_matrix(rows_B, columns_B, &correct_result);
  for (int i = 0; i < rows_A; i++) {
    for (int j = 0; j < columns_A; j++) {
      matrixA.matrix[i][j] = k;
      k++;
    }
  }
  k = -56.987654321;
  for (int i = 0; i < rows_B; i++) {
    for (int j = 0; j < columns_B; j++) {
      matrixB.matrix[i][j] = k;
      k++;
    }
  }
  k = -56.987654321;
  for (int i = 0; i < rows_B; i++) {
    for (int j = 0; j < columns_B; j++) {
      correct_result.matrix[i][j] = k * 2;
      k++;
    }
  }
  ck_assert_int_eq(0, s21_sum_matrix(&matrixA, &matrixB, &result));
  for (int i = 0; i < rows_B; i++) {
    for (int j = 0; j < columns_B; j++) {
      ck_assert_ldouble_eq_tol(correct_result.matrix[i][j], result.matrix[i][j],
                               1e-7);
    }
  }
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct_result);
}
END_TEST

START_TEST(sum_calc_error) {
  matrix_t matrixA;
  matrix_t matrixB;
  matrix_t result;
  int rows_A = 3, columns_A = 3;
  int rows_B = 2, columns_B = 3;
  double k = 1.1234567;
  s21_create_matrix(rows_A, columns_A, &matrixA);
  s21_create_matrix(rows_B, columns_B, &matrixB);
  for (int i = 0; i < rows_A; i++) {
    for (int j = 0; j < columns_A; j++) {
      matrixA.matrix[i][j] = k;
      k++;
    }
  }
  k = 1.1234567;
  for (int i = 0; i < rows_B; i++) {
    for (int j = 0; j < columns_B; j++) {
      matrixB.matrix[i][j] = k;
      k++;
    }
  }
  ck_assert_int_eq(2, s21_sum_matrix(&matrixA, &matrixB, &result));
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
}
END_TEST

START_TEST(sum_incorrect) {
  matrix_t matrixA;
  matrix_t matrixB;
  matrix_t result;
  matrixB.matrix = NULL;
  int rows_A = 2, columns_A = 3;
  matrixB.rows = 2, matrixB.columns = 3;
  s21_create_matrix(rows_A, columns_A, &matrixA);
  ck_assert_int_eq(1, s21_sum_matrix(&matrixA, &matrixB, &result));
  s21_remove_matrix(&matrixA);
}
END_TEST

START_TEST(sum_incorrect2) {
  matrix_t matrixA = {0};
  matrix_t matrixB = {0};
  matrix_t result;
  int rows_A = 2, columns_A = 3;
  matrixB.rows = -1, matrixB.columns = 3;
  s21_create_matrix(rows_A, columns_A, &matrixA);
  ck_assert_int_eq(1, s21_sum_matrix(&matrixA, &matrixB, &result));
  s21_remove_matrix(&matrixA);
}
END_TEST

START_TEST(sub_correct1) {
  matrix_t matrixA;
  matrix_t matrixB;
  matrix_t result;
  matrix_t correct_result;
  int rows_A = 2, columns_A = 3;
  int rows_B = 2, columns_B = 3;
  double k = 1.1234567;
  s21_create_matrix(rows_A, columns_A, &matrixA);
  s21_create_matrix(rows_B, columns_B, &matrixB);
  s21_create_matrix(rows_B, columns_B, &correct_result);
  for (int i = 0; i < rows_A; i++) {
    for (int j = 0; j < columns_A; j++) {
      matrixA.matrix[i][j] = k;
      k++;
    }
  }
  k = 1.1234567;
  for (int i = 0; i < rows_B; i++) {
    for (int j = 0; j < columns_B; j++) {
      matrixB.matrix[i][j] = k;
      k++;
    }
  }
  ck_assert_int_eq(0, s21_sub_matrix(&matrixA, &matrixB, &result));
  for (int i = 0; i < rows_B; i++) {
    for (int j = 0; j < columns_B; j++) {
      ck_assert_ldouble_eq_tol(correct_result.matrix[i][j], result.matrix[i][j],
                               1e-7);
    }
  }
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct_result);
}
END_TEST

START_TEST(sub_correct2) {
  matrix_t matrixA;
  matrix_t matrixB;
  matrix_t result;
  matrix_t correct_result;
  int rows_A = 4, columns_A = 4;
  int rows_B = 4, columns_B = 4;
  double k = -56.987654321;
  s21_create_matrix(rows_A, columns_A, &matrixA);
  s21_create_matrix(rows_B, columns_B, &matrixB);
  s21_create_matrix(rows_B, columns_B, &correct_result);
  for (int i = 0; i < rows_A; i++) {
    for (int j = 0; j < columns_A; j++) {
      matrixA.matrix[i][j] = k;
      k--;
    }
  }
  k = 56.987654321;
  for (int i = 0; i < rows_B; i++) {
    for (int j = 0; j < columns_B; j++) {
      matrixB.matrix[i][j] = k;
      k++;
    }
  }
  k = -56.987654321;
  for (int i = 0; i < rows_B; i++) {
    for (int j = 0; j < columns_B; j++) {
      correct_result.matrix[i][j] = k * 2;
      k--;
    }
  }
  ck_assert_int_eq(0, s21_sub_matrix(&matrixA, &matrixB, &result));
  for (int i = 0; i < rows_B; i++) {
    for (int j = 0; j < columns_B; j++) {
      ck_assert_ldouble_eq_tol(correct_result.matrix[i][j], result.matrix[i][j],
                               1e-7);
    }
  }
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct_result);
}
END_TEST

START_TEST(sub_calc_error) {
  matrix_t matrixA;
  matrix_t matrixB;
  matrix_t result;
  int rows_A = 3, columns_A = 3;
  int rows_B = 2, columns_B = 3;
  double k = 1.1234567;
  s21_create_matrix(rows_A, columns_A, &matrixA);
  s21_create_matrix(rows_B, columns_B, &matrixB);
  for (int i = 0; i < rows_A; i++) {
    for (int j = 0; j < columns_A; j++) {
      matrixA.matrix[i][j] = k;
      k++;
    }
  }
  k = 1.1234567;
  for (int i = 0; i < rows_B; i++) {
    for (int j = 0; j < columns_B; j++) {
      matrixB.matrix[i][j] = k;
      k++;
    }
  }
  ck_assert_int_eq(2, s21_sub_matrix(&matrixA, &matrixB, &result));
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
}
END_TEST

START_TEST(sub_incorrect) {
  matrix_t matrixA;
  matrix_t matrixB;
  matrix_t result;
  matrixB.matrix = NULL;
  int rows_A = 2, columns_A = 3;
  matrixB.rows = 2, matrixB.columns = 3;
  s21_create_matrix(rows_A, columns_A, &matrixA);
  ck_assert_int_eq(1, s21_sub_matrix(&matrixA, &matrixB, &result));
  s21_remove_matrix(&matrixA);
}
END_TEST

START_TEST(mult_number) {
  matrix_t matrixA;
  matrix_t result;
  matrix_t correct_result;
  int rows_A = 4, columns_A = 4;
  double k = -56.987654321, num = 1.1234567;
  s21_create_matrix(rows_A, columns_A, &matrixA);
  s21_create_matrix(rows_A, columns_A, &correct_result);
  for (int i = 0; i < rows_A; i++) {
    for (int j = 0; j < columns_A; j++) {
      matrixA.matrix[i][j] = k;
      k++;
    }
  }
  k = -56.987654321;
  for (int i = 0; i < rows_A; i++) {
    for (int j = 0; j < columns_A; j++) {
      correct_result.matrix[i][j] = k * num;
      k++;
    }
  }
  ck_assert_int_eq(0, s21_mult_number(&matrixA, num, &result));
  for (int i = 0; i < rows_A; i++) {
    for (int j = 0; j < columns_A; j++) {
      ck_assert_ldouble_eq_tol(correct_result.matrix[i][j], result.matrix[i][j],
                               1e-7);
    }
  }
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct_result);
}
END_TEST

START_TEST(mult_number2) {
  matrix_t matrixA;
  matrix_t result;
  matrix_t correct_result;
  int rows_A = 4, columns_A = 4;
  double k = -56.987654321, num = 0;
  s21_create_matrix(rows_A, columns_A, &matrixA);
  s21_create_matrix(rows_A, columns_A, &correct_result);
  for (int i = 0; i < rows_A; i++) {
    for (int j = 0; j < columns_A; j++) {
      matrixA.matrix[i][j] = k;
      k++;
    }
  }
  ck_assert_int_eq(0, s21_mult_number(&matrixA, num, &result));
  for (int i = 0; i < rows_A; i++) {
    for (int j = 0; j < columns_A; j++) {
      ck_assert_ldouble_eq_tol(correct_result.matrix[i][j], result.matrix[i][j],
                               1e-7);
    }
  }
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct_result);
}
END_TEST

START_TEST(mult_number_incorrect) {
  matrix_t matrixA;
  matrix_t result;
  int rows_A = -4, columns_A = 4;
  double num = 2;
  s21_create_matrix(rows_A, columns_A, &matrixA);
  ck_assert_int_eq(1, s21_mult_number(&matrixA, num, &result));
  s21_remove_matrix(&matrixA);
}
END_TEST

START_TEST(mult_number_calc_error) {
  matrix_t matrixA;
  matrix_t result;
  int rows_A = 4, columns_A = 4;
  double k = -56.987654321, num = INFINITY;
  s21_create_matrix(rows_A, columns_A, &matrixA);
  for (int i = 0; i < rows_A; i++) {
    for (int j = 0; j < columns_A; j++) {
      matrixA.matrix[i][j] = k;
      k++;
    }
  }
  ck_assert_int_eq(2, s21_mult_number(&matrixA, num, &result));
  s21_remove_matrix(&matrixA);
}
END_TEST

START_TEST(mult_matrix_correct) {
  matrix_t matrixA;
  matrix_t matrixB;
  matrix_t result;
  matrix_t correct_result;
  int rows_A = 2, columns_A = 3;
  int rows_B = 3, columns_B = 2;
  double k = 1.1234567;
  s21_create_matrix(rows_A, columns_A, &matrixA);
  s21_create_matrix(rows_B, columns_B, &matrixB);
  s21_create_matrix(rows_B, columns_B, &correct_result);
  for (int i = 0; i < rows_A; i++) {
    for (int j = 0; j < columns_A; j++) {
      matrixA.matrix[i][j] = k;
      k++;
    }
  }
  k = 56.987654321;
  for (int i = 0; i < rows_B; i++) {
    for (int j = 0; j < columns_B; j++) {
      matrixB.matrix[i][j] = k;
      k++;
    }
  }
  correct_result.matrix[0][0] = 379.7731893;
  correct_result.matrix[0][1] = 386.1435594;
  correct_result.matrix[1][0] = 910.6620782;
  correct_result.matrix[1][1] = 926.0324483;
  ck_assert_int_eq(0, s21_mult_matrix(&matrixA, &matrixB, &result));
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      ck_assert_ldouble_eq_tol(correct_result.matrix[i][j], result.matrix[i][j],
                               1e-7);
    }
  }
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct_result);
}
END_TEST

START_TEST(mult_matrix_calc_error) {
  matrix_t matrixA;
  matrix_t matrixB;
  matrix_t result;
  int rows_A = 2, columns_A = 3;
  int rows_B = 4, columns_B = 4;
  double k = 1.1234567;
  s21_create_matrix(rows_A, columns_A, &matrixA);
  s21_create_matrix(rows_B, columns_B, &matrixB);
  for (int i = 0; i < rows_A; i++) {
    for (int j = 0; j < columns_A; j++) {
      matrixA.matrix[i][j] = k;
      k++;
    }
  }
  k = 56.987654321;
  for (int i = 0; i < rows_B; i++) {
    for (int j = 0; j < columns_B; j++) {
      matrixB.matrix[i][j] = k;
      k++;
    }
  }
  ck_assert_int_eq(2, s21_mult_matrix(&matrixA, &matrixB, &result));
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
}
END_TEST

START_TEST(mult_matrix_incorrect) {
  matrix_t matrixA;
  matrix_t matrixB;
  matrix_t result;
  int rows_A = 2, columns_A = 3;
  matrixB.rows = 3, matrixB.columns = 2;
  double k = 1.1234567;
  s21_create_matrix(rows_A, columns_A, &matrixA);
  matrixB.matrix = NULL;
  for (int i = 0; i < rows_A; i++) {
    for (int j = 0; j < columns_A; j++) {
      matrixA.matrix[i][j] = k;
      k++;
    }
  }
  ck_assert_int_eq(1, s21_mult_matrix(&matrixA, &matrixB, &result));
  s21_remove_matrix(&matrixA);
}
END_TEST

START_TEST(transpose) {
  matrix_t matrixA;
  matrix_t result;
  matrix_t correct_result;
  int rows_A = 3, columns_A = 2, k = 1;
  s21_create_matrix(rows_A, columns_A, &matrixA);
  s21_create_matrix(columns_A, rows_A, &correct_result);
  matrixA.matrix[0][0] = 1;
  matrixA.matrix[1][0] = 2;
  matrixA.matrix[2][0] = 3;
  matrixA.matrix[0][1] = 4;
  matrixA.matrix[1][1] = 5;
  matrixA.matrix[2][1] = 6;
  for (int i = 0; i < correct_result.rows; i++) {
    for (int j = 0; j < correct_result.columns; j++) {
      correct_result.matrix[i][j] = k;
      k++;
    }
  }
  ck_assert_int_eq(0, s21_transpose(&matrixA, &result));
  for (int i = 0; i < correct_result.rows; i++) {
    for (int j = 0; j < correct_result.columns; j++) {
      ck_assert_ldouble_eq_tol(correct_result.matrix[i][j], result.matrix[i][j],
                               1e-7);
    }
  }
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&correct_result);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transpose2) {
  matrix_t matrixA;
  matrix_t result;
  matrix_t correct_result;
  int rows_A = 3, columns_A = 3;
  s21_create_matrix(rows_A, columns_A, &matrixA);
  matrixA.matrix[0][0] = 4;
  matrixA.matrix[1][0] = 5;
  matrixA.matrix[2][0] = 6;
  matrixA.matrix[0][1] = 7;
  matrixA.matrix[1][1] = 8;
  matrixA.matrix[2][1] = 9;
  matrixA.matrix[0][2] = 1;
  matrixA.matrix[1][2] = 2;
  matrixA.matrix[2][2] = 3;
  s21_create_matrix(columns_A, rows_A, &correct_result);
  correct_result.matrix[0][0] = 4;
  correct_result.matrix[1][0] = 7;
  correct_result.matrix[2][0] = 1;
  correct_result.matrix[0][1] = 5;
  correct_result.matrix[1][1] = 8;
  correct_result.matrix[2][1] = 2;
  correct_result.matrix[0][2] = 6;
  correct_result.matrix[1][2] = 9;
  correct_result.matrix[2][2] = 3;
  ck_assert_int_eq(0, s21_transpose(&matrixA, &result));
  for (int i = 0; i < correct_result.rows; i++) {
    for (int j = 0; j < correct_result.columns; j++) {
      ck_assert_ldouble_eq_tol(correct_result.matrix[i][j], result.matrix[i][j],
                               1e-7);
    }
  }
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&correct_result);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transpose_incorrect) {
  matrix_t matrixA;
  matrix_t result;
  matrixA.matrix = NULL;
  ck_assert_int_eq(1, s21_transpose(&matrixA, &result));
}
END_TEST

START_TEST(calc_complements1) {
  matrix_t matrixA;
  matrix_t result;
  matrix_t correct_result;
  int rows_A = 3, columns_A = 3;
  s21_create_matrix(rows_A, columns_A, &matrixA);
  matrixA.matrix[0][0] = 1;
  matrixA.matrix[1][0] = 0;
  matrixA.matrix[2][0] = 5;
  matrixA.matrix[0][1] = 2;
  matrixA.matrix[1][1] = 4;
  matrixA.matrix[2][1] = 2;
  matrixA.matrix[0][2] = 3;
  matrixA.matrix[1][2] = 2;
  matrixA.matrix[2][2] = 1;
  s21_create_matrix(columns_A, rows_A, &correct_result);
  correct_result.matrix[0][0] = 0;
  correct_result.matrix[1][0] = 4;
  correct_result.matrix[2][0] = -8;
  correct_result.matrix[0][1] = 10;
  correct_result.matrix[1][1] = -14;
  correct_result.matrix[2][1] = -2;
  correct_result.matrix[0][2] = -20;
  correct_result.matrix[1][2] = 8;
  correct_result.matrix[2][2] = 4;
  ck_assert_int_eq(0, s21_calc_complements(&matrixA, &result));
  for (int i = 0; i < correct_result.rows; i++) {
    for (int j = 0; j < correct_result.columns; j++) {
      ck_assert_ldouble_eq_tol(correct_result.matrix[i][j], result.matrix[i][j],
                               1e-7);
    }
  }
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&correct_result);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(calc_complements2) {
  matrix_t matrixA;
  matrix_t result;
  matrix_t correct_result;
  int rows_A = 3, columns_A = 3;
  s21_create_matrix(rows_A, columns_A, &matrixA);
  matrixA.matrix[0][0] = 2;
  matrixA.matrix[1][0] = 6;
  matrixA.matrix[2][0] = 5;
  matrixA.matrix[0][1] = 5;
  matrixA.matrix[1][1] = 3;
  matrixA.matrix[2][1] = -2;
  matrixA.matrix[0][2] = 7;
  matrixA.matrix[1][2] = 4;
  matrixA.matrix[2][2] = -3;
  s21_create_matrix(columns_A, rows_A, &correct_result);
  correct_result.matrix[0][0] = -1;
  correct_result.matrix[1][0] = 1;
  correct_result.matrix[2][0] = -1;
  correct_result.matrix[0][1] = 38;
  correct_result.matrix[1][1] = -41;
  correct_result.matrix[2][1] = 34;
  correct_result.matrix[0][2] = -27;
  correct_result.matrix[1][2] = 29;
  correct_result.matrix[2][2] = -24;
  ck_assert_int_eq(0, s21_calc_complements(&matrixA, &result));
  for (int i = 0; i < correct_result.rows; i++) {
    for (int j = 0; j < correct_result.columns; j++) {
      ck_assert_ldouble_eq_tol(correct_result.matrix[i][j], result.matrix[i][j],
                               1e-7);
    }
  }
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&correct_result);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(calc_incorrect) {
  matrix_t matrixA;
  matrix_t result;
  int rows_A = -3, columns_A = 3;
  s21_create_matrix(rows_A, columns_A, &matrixA);
  ck_assert_int_eq(1, s21_calc_complements(&matrixA, &result));
  s21_remove_matrix(&matrixA);
}
END_TEST

START_TEST(calc_incorrect2) {
  matrix_t *matrixA = NULL;
  matrix_t result;
  ck_assert_int_eq(1, s21_calc_complements(matrixA, &result));
}
END_TEST

START_TEST(calc_comp_calc_error) {
  matrix_t matrixA;
  matrix_t result;
  int rows_A = 3, columns_A = 6;
  s21_create_matrix(rows_A, columns_A, &matrixA);
  ck_assert_int_eq(2, s21_calc_complements(&matrixA, &result));
  s21_remove_matrix(&matrixA);
}
END_TEST

START_TEST(determinant1) {
  matrix_t matrixA;
  double result = 0, correct_result = 0;
  int rows_A = 3, columns_A = 3;
  s21_create_matrix(rows_A, columns_A, &matrixA);
  matrixA.matrix[0][0] = 1;
  matrixA.matrix[1][0] = 4;
  matrixA.matrix[2][0] = 7;
  matrixA.matrix[0][1] = 2;
  matrixA.matrix[1][1] = 5;
  matrixA.matrix[2][1] = 8;
  matrixA.matrix[0][2] = 3;
  matrixA.matrix[1][2] = 6;
  matrixA.matrix[2][2] = 9;
  ck_assert_int_eq(0, s21_determinant(&matrixA, &result));
  correct_result = 0;
  ck_assert_ldouble_eq_tol(correct_result, result, 1e-7);
  s21_remove_matrix(&matrixA);
}
END_TEST

START_TEST(determinant2) {
  matrix_t matrixA;
  double result = 0, correct_result = 0;
  int rows_A = 3, columns_A = 3;
  s21_create_matrix(rows_A, columns_A, &matrixA);
  matrixA.matrix[0][0] = 2;
  matrixA.matrix[1][0] = 6;
  matrixA.matrix[2][0] = 5;
  matrixA.matrix[0][1] = 5;
  matrixA.matrix[1][1] = 3;
  matrixA.matrix[2][1] = -2;
  matrixA.matrix[0][2] = 7;
  matrixA.matrix[1][2] = 4;
  matrixA.matrix[2][2] = -3;
  ck_assert_int_eq(0, s21_determinant(&matrixA, &result));
  correct_result = -1;
  ck_assert_ldouble_eq_tol(correct_result, result, 1e-7);
  s21_remove_matrix(&matrixA);
}
END_TEST

START_TEST(determinant_calc_error) {
  matrix_t matrixA;
  double result = 0;
  int rows_A = 1, columns_A = 5;
  s21_create_matrix(rows_A, columns_A, &matrixA);
  ck_assert_int_eq(2, s21_determinant(&matrixA, &result));
  s21_remove_matrix(&matrixA);
}
END_TEST

START_TEST(determinant_incorrect) {
  matrix_t matrixA;
  double result = 0;
  matrixA.matrix = NULL;
  ck_assert_int_eq(1, s21_determinant(&matrixA, &result));
}
END_TEST

START_TEST(inverse_matrix) {
  matrix_t matrixA;
  matrix_t result;
  matrix_t correct_result;
  int rows_A = 3, columns_A = 3;
  s21_create_matrix(rows_A, columns_A, &matrixA);
  matrixA.matrix[0][0] = 1;
  matrixA.matrix[1][0] = 0;
  matrixA.matrix[2][0] = 5;
  matrixA.matrix[0][1] = -2;
  matrixA.matrix[1][1] = 4;
  matrixA.matrix[2][1] = 0;
  matrixA.matrix[0][2] = 3;
  matrixA.matrix[1][2] = -1;
  matrixA.matrix[2][2] = 0;
  s21_create_matrix(columns_A, rows_A, &correct_result);
  correct_result.matrix[0][0] = 0;
  correct_result.matrix[1][0] = 0.1;
  correct_result.matrix[2][0] = 0.4;
  correct_result.matrix[0][1] = 0;
  correct_result.matrix[1][1] = 0.3;
  correct_result.matrix[2][1] = 0.2;
  correct_result.matrix[0][2] = 0.2;
  correct_result.matrix[1][2] = -0.02;
  correct_result.matrix[2][2] = -0.08;
  ck_assert_int_eq(0, s21_inverse_matrix(&matrixA, &result));
  for (int i = 0; i < correct_result.rows; i++) {
    for (int j = 0; j < correct_result.columns; j++) {
      ck_assert_ldouble_eq_tol(correct_result.matrix[i][j], result.matrix[i][j],
                               1e-7);
    }
  }
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&correct_result);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix2) {
  matrix_t matrixA;
  matrix_t result;
  matrix_t correct_result;
  int rows_A = 3, columns_A = 3;
  s21_create_matrix(rows_A, columns_A, &matrixA);
  matrixA.matrix[0][0] = 2;
  matrixA.matrix[1][0] = 6;
  matrixA.matrix[2][0] = 5;
  matrixA.matrix[0][1] = 5;
  matrixA.matrix[1][1] = 3;
  matrixA.matrix[2][1] = -2;
  matrixA.matrix[0][2] = 7;
  matrixA.matrix[1][2] = 4;
  matrixA.matrix[2][2] = -3;
  s21_create_matrix(columns_A, rows_A, &correct_result);
  correct_result.matrix[0][0] = 1;
  correct_result.matrix[1][0] = -38;
  correct_result.matrix[2][0] = 27;
  correct_result.matrix[0][1] = -1;
  correct_result.matrix[1][1] = 41;
  correct_result.matrix[2][1] = -29;
  correct_result.matrix[0][2] = 1;
  correct_result.matrix[1][2] = -34;
  correct_result.matrix[2][2] = 24;
  ck_assert_int_eq(0, s21_inverse_matrix(&matrixA, &result));
  for (int i = 0; i < correct_result.rows; i++) {
    for (int j = 0; j < correct_result.columns; j++) {
      ck_assert_ldouble_eq_tol(correct_result.matrix[i][j], result.matrix[i][j],
                               1e-7);
    }
  }
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&correct_result);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix3) {
  matrix_t matrixA;
  matrix_t result;
  int rows_A = 1, columns_A = 1;
  s21_create_matrix(rows_A, columns_A, &matrixA);
  matrixA.matrix[0][0] = 21.424221;
  ck_assert_int_eq(0, s21_inverse_matrix(&matrixA, &result));
  ck_assert_ldouble_eq_tol(1 / matrixA.matrix[0][0], result.matrix[0][0], 1e-7);
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_calc_error) {
  matrix_t matrixA;
  matrix_t result;
  int rows_A = 3, columns_A = 3;
  s21_create_matrix(rows_A, columns_A, &matrixA);
  matrixA.matrix[0][0] = 4;
  matrixA.matrix[1][0] = 5;
  matrixA.matrix[2][0] = 6;
  matrixA.matrix[0][1] = 7;
  matrixA.matrix[1][1] = 8;
  matrixA.matrix[2][1] = 9;
  matrixA.matrix[0][2] = 1;
  matrixA.matrix[1][2] = 2;
  matrixA.matrix[2][2] = 3;
  ck_assert_int_eq(2, s21_inverse_matrix(&matrixA, &result));
  s21_remove_matrix(&matrixA);
}
END_TEST

START_TEST(inverse_matrix_incorrect) {
  matrix_t matrixA;
  matrix_t result;
  matrixA.matrix = NULL;
  ck_assert_int_eq(1, s21_inverse_matrix(&matrixA, &result));
}
END_TEST

int main(void) {
  Suite *suite =
      suite_create("S21_TEST");  // создание наборов тестов и с именем S21_TEST
  SRunner *srunner = srunner_create(suite);

  TCase *create_correct_Test =
      tcase_create("create_correct");  // создание тестового примера с именем
  suite_add_tcase(suite, create_correct_Test);  // добавление в тестовый набор
  tcase_add_test(
      create_correct_Test,
      create_correct);  // добавление тестовой функции в тестовый пример

  TCase *create_correct2_Test = tcase_create("create_correct2");
  suite_add_tcase(suite, create_correct2_Test);
  tcase_add_test(create_correct2_Test, create_correct2);

  TCase *create_incorrect1_Test = tcase_create("create_incorrect1");
  suite_add_tcase(suite, create_incorrect1_Test);
  tcase_add_test(create_incorrect1_Test, create_incorrect1);

  TCase *create_incorrect2_Test = tcase_create("create_incorrect2");
  suite_add_tcase(suite, create_incorrect2_Test);
  tcase_add_test(create_incorrect2_Test, create_incorrect2);

  TCase *create_incorrect3_Test = tcase_create("create_incorrect3");
  suite_add_tcase(suite, create_incorrect3_Test);
  tcase_add_test(create_incorrect3_Test, create_incorrect3);

  TCase *eq_matrix_incorrect_Test = tcase_create("eq_matrix_incorrect");
  suite_add_tcase(suite, eq_matrix_incorrect_Test);
  tcase_add_test(eq_matrix_incorrect_Test, eq_matrix_incorrect);

  TCase *eq_matrix_eq_Test = tcase_create("eq_matrix_eq");
  suite_add_tcase(suite, eq_matrix_eq_Test);
  tcase_add_test(eq_matrix_eq_Test, eq_matrix_eq);

  TCase *eq_matrix_eq2_Test = tcase_create("eq_matrix_eq2");
  suite_add_tcase(suite, eq_matrix_eq2_Test);
  tcase_add_test(eq_matrix_eq2_Test, eq_matrix_eq2);

  TCase *eq_matrix_eq3_Test = tcase_create("eq_matrix_eq3");
  suite_add_tcase(suite, eq_matrix_eq3_Test);
  tcase_add_test(eq_matrix_eq3_Test, eq_matrix_eq3);

  TCase *eq_matrix_eq4_Test = tcase_create("eq_matrix_eq4");
  suite_add_tcase(suite, eq_matrix_eq4_Test);
  tcase_add_test(eq_matrix_eq4_Test, eq_matrix_eq4);

  TCase *eq_matrix_not_eq1_Test = tcase_create("eq_matrix_not_eq1");
  suite_add_tcase(suite, eq_matrix_not_eq1_Test);
  tcase_add_test(eq_matrix_not_eq1_Test, eq_matrix_not_eq1);

  TCase *eq_matrix_not_eq2_Test = tcase_create("eq_matrix_not_eq2");
  suite_add_tcase(suite, eq_matrix_not_eq2_Test);
  tcase_add_test(eq_matrix_not_eq2_Test, eq_matrix_not_eq2);

  TCase *sum_correct1_Test = tcase_create("sum_correct1");
  suite_add_tcase(suite, sum_correct1_Test);
  tcase_add_test(sum_correct1_Test, sum_correct1);

  TCase *sum_correct2_Test = tcase_create("sum_correct2");
  suite_add_tcase(suite, sum_correct2_Test);
  tcase_add_test(sum_correct2_Test, sum_correct2);

  TCase *sum_calc_error_Test = tcase_create("sum_calc_error");
  suite_add_tcase(suite, sum_calc_error_Test);
  tcase_add_test(sum_calc_error_Test, sum_calc_error);

  TCase *sum_incorrect_Test = tcase_create("sum_incorrect");
  suite_add_tcase(suite, sum_incorrect_Test);
  tcase_add_test(sum_incorrect_Test, sum_incorrect);

  TCase *sum_incorrect2_Test = tcase_create("sum_incorrect2");
  suite_add_tcase(suite, sum_incorrect2_Test);
  tcase_add_test(sum_incorrect2_Test, sum_incorrect2);

  TCase *sub_correct1_Test = tcase_create("sub_correct1");
  suite_add_tcase(suite, sub_correct1_Test);
  tcase_add_test(sub_correct1_Test, sub_correct1);

  TCase *sub_correct2_Test = tcase_create("sub_correct2");
  suite_add_tcase(suite, sub_correct2_Test);
  tcase_add_test(sub_correct2_Test, sub_correct2);

  TCase *sub_calc_error_Test = tcase_create("sub_calc_error");
  suite_add_tcase(suite, sub_calc_error_Test);
  tcase_add_test(sub_calc_error_Test, sub_calc_error);

  TCase *sub_incorrect_Test = tcase_create("sub_incorrect");
  suite_add_tcase(suite, sub_incorrect_Test);
  tcase_add_test(sub_incorrect_Test, sub_incorrect);

  TCase *mult_number_Test = tcase_create("mult_number");
  suite_add_tcase(suite, mult_number_Test);
  tcase_add_test(mult_number_Test, mult_number);

  TCase *mult_number2_Test = tcase_create("mult_number2");
  suite_add_tcase(suite, mult_number2_Test);
  tcase_add_test(mult_number2_Test, mult_number2);

  TCase *mult_number_incorrect_Test = tcase_create("mult_number_incorrect");
  suite_add_tcase(suite, mult_number_incorrect_Test);
  tcase_add_test(mult_number_incorrect_Test, mult_number_incorrect);

  TCase *mult_number_calc_error_Test = tcase_create("mult_number_calc_error");
  suite_add_tcase(suite, mult_number_calc_error_Test);
  tcase_add_test(mult_number_calc_error_Test, mult_number_calc_error);

  TCase *mult_matrix_correct_Test = tcase_create("mult_matrix_correct");
  suite_add_tcase(suite, mult_matrix_correct_Test);
  tcase_add_test(mult_matrix_correct_Test, mult_matrix_correct);

  TCase *mult_matrix_calc_error_Test = tcase_create("mult_matrix_calc_error");
  suite_add_tcase(suite, mult_matrix_calc_error_Test);
  tcase_add_test(mult_matrix_calc_error_Test, mult_matrix_calc_error);

  TCase *mult_matrix_incorrect_Test = tcase_create("mult_matrix_incorrect");
  suite_add_tcase(suite, mult_matrix_incorrect_Test);
  tcase_add_test(mult_matrix_incorrect_Test, mult_matrix_incorrect);

  TCase *transpose_Test = tcase_create("transpose");
  suite_add_tcase(suite, transpose_Test);
  tcase_add_test(transpose_Test, transpose);

  TCase *transpose2_Test = tcase_create("transpose2");
  suite_add_tcase(suite, transpose2_Test);
  tcase_add_test(transpose2_Test, transpose2);

  TCase *transpose_incorrect_Test = tcase_create("transpose_incorrect");
  suite_add_tcase(suite, transpose_incorrect_Test);
  tcase_add_test(transpose_incorrect_Test, transpose_incorrect);

  TCase *calc_complements1_Test = tcase_create("calc_complements1");
  suite_add_tcase(suite, calc_complements1_Test);
  tcase_add_test(calc_complements1_Test, calc_complements1);

  TCase *calc_complements2_Test = tcase_create("calc_complements2");
  suite_add_tcase(suite, calc_complements2_Test);
  tcase_add_test(calc_complements2_Test, calc_complements2);

  TCase *calc_incorrect_Test = tcase_create("calc_incorrect");
  suite_add_tcase(suite, calc_incorrect_Test);
  tcase_add_test(calc_incorrect_Test, calc_incorrect);

  TCase *calc_incorrect2_Test = tcase_create("calc_incorrect2");
  suite_add_tcase(suite, calc_incorrect2_Test);
  tcase_add_test(calc_incorrect2_Test, calc_incorrect2);

  TCase *calc_comp_calc_errorTest = tcase_create("calc_comp_calc_error");
  suite_add_tcase(suite, calc_comp_calc_errorTest);
  tcase_add_test(calc_comp_calc_errorTest, calc_comp_calc_error);

  TCase *determinant1_Test = tcase_create("determinant1");
  suite_add_tcase(suite, determinant1_Test);
  tcase_add_test(determinant1_Test, determinant1);

  TCase *determinant2_Test = tcase_create("determinant2");
  suite_add_tcase(suite, determinant2_Test);
  tcase_add_test(determinant2_Test, determinant2);

  TCase *determinant_calc_error_Test = tcase_create("determinant_calc_error");
  suite_add_tcase(suite, determinant_calc_error_Test);
  tcase_add_test(determinant_calc_error_Test, determinant_calc_error);

  TCase *determinant_incorrect_Test = tcase_create("determinant_incorrect");
  suite_add_tcase(suite, determinant_incorrect_Test);
  tcase_add_test(determinant_incorrect_Test, determinant_incorrect);

  TCase *inverse_matrix_Test = tcase_create("inverse_matrix");
  suite_add_tcase(suite, inverse_matrix_Test);
  tcase_add_test(inverse_matrix_Test, inverse_matrix);

  TCase *inverse_matrix2_Test = tcase_create("inverse_matrix2");
  suite_add_tcase(suite, inverse_matrix2_Test);
  tcase_add_test(inverse_matrix2_Test, inverse_matrix2);

  TCase *inverse_matrix3_Test = tcase_create("inverse_matrix3");
  suite_add_tcase(suite, inverse_matrix3_Test);
  tcase_add_test(inverse_matrix3_Test, inverse_matrix3);

  TCase *inverse_matrix_calc_error_Test =
      tcase_create("inverse_matrix_calc_error");
  suite_add_tcase(suite, inverse_matrix_calc_error_Test);
  tcase_add_test(inverse_matrix_calc_error_Test, inverse_matrix_calc_error);

  TCase *inverse_matrix_incorrect_Test =
      tcase_create("inverse_matrix_incorrect");
  suite_add_tcase(suite, inverse_matrix_incorrect_Test);
  tcase_add_test(inverse_matrix_incorrect_Test, inverse_matrix_incorrect);

  srunner_run_all(srunner, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return number_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
