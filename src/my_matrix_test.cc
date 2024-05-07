#include <gtest/gtest.h>

#include <cstdlib>

#include "my_matrix_oop.h"

double dum_sum_1_1[] = {-2,  -4,  -6,  -8,  -10, -12, -14, -16,
                        -18, -20, -22, -24, -0,  -0,  -0};

double dum_sum_1_2[] = {-1, -2,  -3,  -4,  -5, -6, -7, -8,
                        -9, -10, -11, -12, -0, -0, -0};

TEST(core_function_test, EqMatrix_1) {
  MYMatrix matrix_1, matrix_2;
  for (int i = 0; i < matrix_1.GetRows(); i++) {
    for (int j = 0; j < matrix_1.GetCols(); j++) {
      matrix_1(i, j) = 1;
      matrix_2(i, j) = 1;
    }
  }
  EXPECT_TRUE(matrix_1.EqMatrix(matrix_2));
}

TEST(core_function_test, EqMatrix_2) {
  MYMatrix matrix_1(5, 3), matrix_2(5, 3);
  matrix_1.InsertArray(dum_sum_1_1);
  matrix_2.InsertArray(dum_sum_1_2);
  EXPECT_FALSE(matrix_1.EqMatrix(matrix_2));
}

TEST(core_function_test, EqMatrix_3) {
  MYMatrix matrix_1(5, 3), matrix_2(4, 3);
  matrix_1.InsertArray(dum_sum_1_1);
  for (int i = 0; i < matrix_2.GetRows(); i++) {
    for (int j = 0; j < matrix_2.GetCols(); j++) {
      matrix_2(i, j) = 1;
    }
  }
  EXPECT_FALSE(matrix_1.EqMatrix(matrix_2));
}

TEST(core_function_test, SumMatrix_1) {
  MYMatrix matrix_1(3, 3), matrix_2(3, 3);
  for (int i = 0; i < matrix_2.GetRows(); i++) {
    for (int j = 0; j < matrix_2.GetCols(); j++) {
      matrix_2(i, j) = 1;
      matrix_1(i, j) = 2;
    }
  }
  matrix_2.SumMatrix(matrix_2);
  EXPECT_TRUE(matrix_1.EqMatrix(matrix_2));
}

TEST(core_function_test, SumMatrix_2) {
  MYMatrix matrix_1(5, 3), matrix_2(4, 3);
  EXPECT_THROW(matrix_1.SumMatrix(matrix_2), std::logic_error);
}

TEST(core_function_test, SubMatrix_1) {
  MYMatrix matrix_1(5, 3), matrix_2(4, 3);
  EXPECT_THROW(matrix_1.SubMatrix(matrix_2), std::logic_error);
}

TEST(core_function_test, SubMatrix_2) {
  MYMatrix matrix_1(3, 3), matrix_2(3, 3);
  for (int i = 0; i < matrix_2.GetRows(); i++) {
    for (int j = 0; j < matrix_2.GetCols(); j++) {
      matrix_2(i, j) = 1;
      matrix_1(i, j) = 2;
    }
  }
  matrix_1.SubMatrix(matrix_2);
  EXPECT_TRUE(matrix_1.EqMatrix(matrix_2));
}

TEST(core_function_test, SubMatrix_3) {
  MYMatrix matrix_1(2, 2), matrix_2(2, 2);
  matrix_1(0, 0) = 2;
  matrix_1(0, 1) = 4;
  matrix_1(1, 0) = 6;
  matrix_1(1, 1) = 8;
  matrix_2.SubMatrix(matrix_1);
  matrix_1 *= -1;
  EXPECT_TRUE(matrix_1.EqMatrix(matrix_2));
}

TEST(core_function_test, MulNumber_1) {
  MYMatrix matrix_1(3, 3), matrix_2(3, 3);
  for (int i = 0; i < matrix_2.GetRows(); i++) {
    for (int j = 0; j < matrix_2.GetCols(); j++) {
      matrix_1(i, j) = 3;
      matrix_2(i, j) = 6;
    }
  }
  matrix_1.MulNumber(2);
  EXPECT_TRUE(matrix_1.EqMatrix(matrix_2));
}

TEST(core_function_test, MulNumber_2) {
  MYMatrix matrix_1(2, 2), matrix_2(2, 2);
  matrix_1(0, 0) = 2;
  matrix_1(0, 1) = 4;
  matrix_1(1, 0) = 6;
  matrix_1(1, 1) = 8;
  matrix_1.MulNumber(0);
  EXPECT_TRUE(matrix_1.EqMatrix(matrix_2));
}

TEST(core_function_test, MulMatrix_1) {
  MYMatrix marix_1(2, 3), mtrix_2(3, 2);
  double count = 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      marix_1(i, j) = count;
      mtrix_2(j, i) = count;
      count++;
    }
  }
  marix_1.MulMatrix(mtrix_2);
  MYMatrix res(2, 2);
  res(0, 0) = 14;
  res(0, 1) = 32;
  res(1, 0) = 32;
  res(1, 1) = 77;
  EXPECT_TRUE(marix_1.EqMatrix(res));
}

TEST(core_function_test, MulMatrix_2) {
  MYMatrix matrix_1(2, 3), matrix_2(4, 2);
  double count = 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      matrix_1(i, j) = count;
      matrix_2(j, i) = count;
      count++;
    }
  }
  EXPECT_THROW(matrix_1.MulMatrix(matrix_2), std::logic_error);
}

TEST(core_function_test, Transpose_1) {
  MYMatrix matrix_1(4, 4), matrix_2(4, 4);
  double count = 1;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1(i, j) = count;
      matrix_2(j, i) = count;
      count++;
    }
  }
  matrix_2 = matrix_2.Transpose();
  EXPECT_TRUE(matrix_2.EqMatrix(matrix_1));
}

TEST(core_function_test, Transpose_2) {
  MYMatrix matrix_1(2, 3), matrix_2(3, 2);
  double count = 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      matrix_1(i, j) = count;
      matrix_2(j, i) = count;
      count++;
    }
  }
  matrix_2 = matrix_2.Transpose();
  EXPECT_TRUE(matrix_1.EqMatrix(matrix_2));
}

TEST(core_function_test, CalcComplements_1) {
  MYMatrix matrix_1(2, 2), matrix_2(2, 2);
  int count = 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      matrix_1(i, j) = count;
      count++;
    }
  }
  matrix_1 = matrix_1.CalcComplements();
  matrix_2(0, 0) = 4;
  matrix_2(0, 1) = -3;
  matrix_2(1, 0) = -2;
  matrix_2(1, 1) = 1;
  EXPECT_TRUE(matrix_1.EqMatrix(matrix_2));
}

TEST(core_function_test, CalcComplements_2) {
  MYMatrix matrix_1(2, 3);
  double count = 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      matrix_1(i, j) = count;
      count++;
    }
  }
  EXPECT_THROW(matrix_1.CalcComplements(), std::logic_error);
}

TEST(core_function_test, Determinant_1) {
  MYMatrix matrix_1(3, 3);
  int count = 1;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix_1(i, j) = count;
      count++;
    }
  }
  EXPECT_DOUBLE_EQ(0, matrix_1.Determinant());
}

TEST(core_function_test, Determinant_2) {
  MYMatrix matrix_1(3, 3);
  int count = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix_1(i, j) = count;
      count += i + j;
    }
    count *= 2;
  }
  EXPECT_DOUBLE_EQ(-12, matrix_1.Determinant());
}

TEST(core_function_test, Inverse_1) {
  MYMatrix matrix_1(2, 2), matrix_2(2, 2);
  int count = 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      matrix_1(i, j) = count;
      count++;
    }
  }
  matrix_1 = matrix_1.InverseMatrix();
  matrix_2(0, 0) = -2;
  matrix_2(0, 1) = 1;
  matrix_2(1, 0) = 1.5;
  matrix_2(1, 1) = -0.5;
  EXPECT_TRUE(matrix_1.EqMatrix(matrix_2));
}

TEST(core_function_test, Inverse_2) {
  MYMatrix matrix_1(2, 2), matrix_2(2, 2);
  matrix_1(0, 0) = 1;
  matrix_1(0, 1) = 1;
  matrix_1(1, 0) = 3;
  matrix_1(1, 1) = 2;
  matrix_1 = matrix_1.InverseMatrix();
  matrix_2(0, 0) = -2;
  matrix_2(0, 1) = 1;
  matrix_2(1, 0) = 3;
  matrix_2(1, 1) = -1;
  EXPECT_TRUE(matrix_1.EqMatrix(matrix_2));
}

TEST(get_set, t1) {
  MYMatrix m1(2, 2);
  m1(1, 1) = 123.456;
  EXPECT_EQ(m1.GetCols(), 2);
  EXPECT_EQ(m1.GetRows(), 2);
  EXPECT_DOUBLE_EQ(m1(1, 1), 123.456);
}

TEST(set_col, t1) {
  MYMatrix m(2, 2);
  m(1, 1) = 123.456;
  m.SetCols(3);
  m(1, 2) = 999.999;
  EXPECT_EQ(m.GetCols(), 3);
  EXPECT_DOUBLE_EQ(m(1, 1), 123.456);
  EXPECT_DOUBLE_EQ(m(1, 2), 999.999);
}

TEST(set_row, t1) {
  MYMatrix m1(2, 2);
  m1(1, 0) = 123.456;
  m1.SetRows(3);
  m1(2, 0) = m1(1, 0);
  EXPECT_EQ(m1.GetRows(), 3);
  EXPECT_EQ(m1.GetCols(), 2);
  EXPECT_DOUBLE_EQ(m1(1, 0), m1(2, 0));
}

TEST(constructors, t1) {
  MYMatrix m1;
  EXPECT_EQ(m1.GetCols(), 0);
  EXPECT_EQ(m1.GetRows(), 0);

  MYMatrix m2(5, 5);
  m2(1, 1) = 123.456;
  EXPECT_EQ(m2.GetCols(), 5);
  EXPECT_EQ(m2.GetRows(), 5);

  MYMatrix m3(m2);
  EXPECT_EQ(m2 == m3, true);

  MYMatrix m4(std::move(m3));
  EXPECT_EQ(m3.GetCols(), 0);
  EXPECT_EQ(m3.GetRows(), 0);
  EXPECT_EQ(m4.GetRows(), 5);
  EXPECT_EQ(m4.GetCols(), 5);
  EXPECT_EQ(m4(1, 1), m2(1, 1));
}

TEST(func1, eq) {
  MYMatrix m1(123, 123);
  MYMatrix m2(m1);

  EXPECT_EQ(m1.EqMatrix(m2), true);
}

TEST(func2, summat) {
  MYMatrix m1(3, 3);
  MYMatrix m2(3, 3);

  m1(0, 0) = 1;
  m1(0, 2) = 2;
  m1(2, 0) = 3;

  m2.SumMatrix(m1);

  EXPECT_EQ(m2(0, 0), 1);
  EXPECT_EQ(m2(0, 2), 2);
  EXPECT_EQ(m2(2, 0), 3);
}

TEST(func3, submat) {
  MYMatrix m1(3, 3);
  MYMatrix m2(3, 3);

  m1(0, 0) = 1;
  m1(0, 2) = 2;
  m1(2, 0) = 3;

  m2.SubMatrix(m1);

  EXPECT_EQ(m2(0, 0), -1);
  EXPECT_EQ(m2(0, 2), -2);
  EXPECT_EQ(m2(2, 0), -3);
}

TEST(func4, mulnum) {
  MYMatrix m2(3, 3);

  m2(0, 0) = 1.3;
  m2(0, 2) = 2.1;
  m2(2, 0) = 3.3;

  m2.MulNumber(0.412);

  EXPECT_EQ(m2(0, 0), 1.3 * 0.412);
  EXPECT_EQ(m2(0, 2), 2.1 * 0.412);
  EXPECT_EQ(m2(2, 0), 3.3 * 0.412);
}

TEST(func5, mulmat) {
  MYMatrix m1(2, 1);
  MYMatrix m2(1, 2);

  m1(0, 0) = 32;
  m1(1, 0) = 12;

  m2(0, 0) = 2;
  m2(0, 1) = 3;

  m1.MulMatrix(m2);

  EXPECT_DOUBLE_EQ(m1(0, 0), 32 * 2);
  EXPECT_DOUBLE_EQ(m1(1, 1), 12 * 3);
}

TEST(func6, transpose) {
  int rows = 2;
  int cols = 3;

  MYMatrix m(rows, cols);
  MYMatrix res(cols, rows);

  for (int i = 0, c = 1; i < rows; i++) {
    for (int j = 0; j < cols; j++, c++) {
      m(i, j) = c;
      res(j, i) = c;
    }
  }

  m = m.Transpose();

  ASSERT_TRUE(m == res);
}

TEST(func7, calccal) {
  MYMatrix m(3, 12);
  EXPECT_ANY_THROW(m.CalcComplements());
}

TEST(func7, calcalc) {
  int rows = 3;
  int cols = 3;

  MYMatrix given(rows, cols);
  MYMatrix expected(rows, cols);

  given(0, 0) = 1.0;
  given(0, 1) = 2.0;
  given(0, 2) = 3.0;
  given(1, 0) = 0.0;
  given(1, 1) = 4.0;
  given(1, 2) = 2.0;
  given(2, 0) = 5.0;
  given(2, 1) = 2.0;
  given(2, 2) = 1.0;

  expected(0, 0) = 0.0;
  expected(0, 1) = 10.0;
  expected(0, 2) = -20.0;
  expected(1, 0) = 4.0;
  expected(1, 1) = -14.0;
  expected(1, 2) = 8.0;
  expected(2, 0) = -8.0;
  expected(2, 1) = -2.0;
  expected(2, 2) = 4.0;

  MYMatrix res = given.CalcComplements();

  ASSERT_TRUE(res == expected);
}

TEST(func8, det) {
  MYMatrix m(5, 5);

  for (uint32_t i = 0; i < 5; i++)
    for (uint32_t j = 0; j < 5; j++) m(i, j) = j;

  ASSERT_NEAR(0, m.Determinant(), 1e-06);
}

TEST(func8, det1) {
  int size = 5;
  MYMatrix m(size, size);

  m(0, 1) = 6;
  m(0, 2) = -2;
  m(0, 3) = -1;
  m(0, 4) = 5;
  m(1, 3) = -9;
  m(1, 4) = -7;
  m(2, 1) = 15;
  m(2, 2) = 35;
  m(3, 1) = -1;
  m(3, 2) = -11;
  m(3, 3) = -2;
  m(3, 4) = 1;
  m(4, 0) = -2;
  m(4, 1) = -2;
  m(4, 2) = 3;
  m(4, 4) = -2;

  double res = m.Determinant();
  ASSERT_NEAR(res, 2480, 1e-6);
}

TEST(func8, det2) {
  int size = 3;
  MYMatrix m(size, size);

  m(0, 0) = 2;
  m(0, 1) = 3;
  m(0, 2) = 1;
  m(1, 0) = 7;
  m(1, 1) = 4;
  m(1, 2) = 1;
  m(2, 0) = 9;
  m(2, 1) = -2;
  m(2, 2) = 1;

  double res = m.Determinant();
  ASSERT_NEAR(res, -32, 1e-6);
}

TEST(func9, inverse) {
  int size = 3;
  MYMatrix given(size, size);
  MYMatrix expected(size, size);

  expected(0, 0) = 44300.0 / 367429.0;
  expected(0, 1) = -236300.0 / 367429.0;
  expected(0, 2) = 200360.0 / 367429.0;
  expected(1, 0) = 20600.0 / 367429.0;
  expected(1, 1) = 56000.0 / 367429.0;
  expected(1, 2) = -156483.0 / 367429.0;
  expected(2, 0) = 30900.0 / 367429.0;
  expected(2, 1) = 84000.0 / 367429.0;
  expected(2, 2) = -51010.0 / 367429.0;

  given(0, 0) = 2.8;
  given(0, 1) = 1.3;
  given(0, 2) = 7.01;
  given(1, 0) = -1.03;
  given(1, 1) = -2.3;
  given(1, 2) = 3.01;
  given(2, 0) = 0;
  given(2, 1) = -3;
  given(2, 2) = 2;

  ASSERT_TRUE(given.InverseMatrix() == expected);
}

TEST(operator_overloading, operator_sum) {
  MYMatrix matrix_1(3, 3), matrix_2(3, 3);
  for (int i = 0; i < matrix_2.GetRows(); i++) {
    for (int j = 0; j < matrix_2.GetCols(); j++) {
      matrix_2(i, j) = 1;
      matrix_1(i, j) = 2;
    }
  }
  matrix_2 += matrix_2;
  EXPECT_TRUE(matrix_1.EqMatrix(matrix_2));
}

TEST(operator_overloading, operator_minus) {
  MYMatrix matrix_1(3, 3), matrix_2(3, 3);
  for (int i = 0; i < matrix_2.GetRows(); i++) {
    for (int j = 0; j < matrix_2.GetCols(); j++) {
      matrix_2(i, j) = 1;
      matrix_1(i, j) = 2;
    }
  }
  matrix_1 -= matrix_2;
  EXPECT_TRUE(matrix_1.EqMatrix(matrix_2));
}

TEST(operator_overloading, operator_mult) {
  MYMatrix matrix_1(2, 3), matrix_2(3, 2);
  double count = 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      matrix_1(i, j) = count;
      matrix_2(j, i) = count;
      count++;
    }
  }
  matrix_1 *= matrix_2;
  MYMatrix res(2, 2);
  res(0, 0) = 14;
  res(0, 1) = 32;
  res(1, 0) = 32;
  res(1, 1) = 77;
  EXPECT_TRUE(matrix_1.EqMatrix(res));
}

TEST(operator_overloading, operator_copy) {
  MYMatrix matrix_1(2, 3), matrix_2(3, 2);
  double count = 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      matrix_1(i, j) = count;
      count++;
    }
  }
  matrix_2 = matrix_1;
  EXPECT_TRUE(matrix_1.EqMatrix(matrix_2));
}

TEST(operator_overloading, operator_sum_both) {
  MYMatrix matrix_1(3, 3), matrix_2(3, 3);
  for (int i = 0; i < matrix_2.GetRows(); i++) {
    for (int j = 0; j < matrix_2.GetCols(); j++) {
      matrix_2(i, j) = 1;
      matrix_1(i, j) = 2;
    }
  }
  matrix_2 = matrix_2 + matrix_2;
  EXPECT_TRUE(matrix_1.EqMatrix(matrix_2));
}

TEST(operator_overloading, operator_sub_both) {
  MYMatrix matrix_1(2, 2), matrix_2(2, 2);
  matrix_1(0, 0) = 2;
  matrix_1(0, 1) = 4;
  matrix_1(1, 0) = 6;
  matrix_1(1, 1) = 8;
  matrix_2 = matrix_2 - matrix_1;
  matrix_1 *= -1;
  EXPECT_TRUE(matrix_1.EqMatrix(matrix_2));
}

TEST(operator_overloading, operator_mult_both) {
  MYMatrix matrix_1(2, 3), matrix_2(3, 2);
  double count = 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      matrix_1(i, j) = count;
      matrix_2(j, i) = count;
      count++;
    }
  }
  matrix_1 = matrix_1 * matrix_2;
  MYMatrix res(2, 2);
  res(0, 0) = 14;
  res(0, 1) = 32;
  res(1, 0) = 32;
  res(1, 1) = 77;
  EXPECT_TRUE(matrix_1.EqMatrix(res));
}

TEST(operator_overloading, operator_mult_number) {
  MYMatrix matrix_1(2, 2), matrix_2(2, 2);
  double count = 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      matrix_1(i, j) = count;
      count++;
    }
  }
  matrix_1 = matrix_1 * 2;
  matrix_2(0, 0) = 2;
  matrix_2(0, 1) = 4;
  matrix_2(1, 0) = 6;
  matrix_2(1, 1) = 8;
  EXPECT_TRUE(matrix_1.EqMatrix(matrix_2));
}

TEST(throw_test, MYMatrix_throw) {
  EXPECT_THROW(MYMatrix matrix_1(-2, -1), std::logic_error);
}

TEST(throw_test, Determinant_throw) {
  MYMatrix matrix_1(2, 3);
  double count = 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      matrix_1(i, j) = count;
      count++;
    }
  }
  EXPECT_THROW(matrix_1.Determinant(), std::logic_error);
}

TEST(throw_test, InverseMatrix_throw) {
  MYMatrix matrix_1(3, 3);
  double count = 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      if (i == 0) {
        matrix_1(i, j) = 0;
      } else
        matrix_1(i, j) = count;
      count++;
    }
  }
  EXPECT_THROW(matrix_1.InverseMatrix(), std::logic_error);
}

TEST(throw_test, InverseMatrix_throw_1) {
  MYMatrix matrix_1(1, 1), matrix_2(1, 1);
  double count = 1;
  for (int i = 0; i < 1; i++) {
    for (int j = 0; j < 1; j++) {
      matrix_1(i, j) = 1;
      matrix_2(i, j) = 2;
      count++;
    }
  }
  matrix_2 = matrix_1.InverseMatrix();
  EXPECT_TRUE(matrix_1.EqMatrix(matrix_2));
}

TEST(core_function_test, SetRows_1) {
  MYMatrix matrix_1(3, 3);
  EXPECT_THROW(matrix_1.SetRows(-1), std::logic_error);
}

TEST(core_function_test, SetCols) {
  MYMatrix matrix_1(3, 3);
  EXPECT_THROW(matrix_1.SetCols(-1), std::logic_error);
}

TEST(core_function_test, operator_1) {
  MYMatrix matrix_1(3, 3);
  EXPECT_THROW(matrix_1(-1, -2), std::logic_error);
}

TEST(core_function_test, operator_2) {
  MYMatrix matrix_1(3, 3);
  EXPECT_THROW(matrix_1(4, 5), std::logic_error);
}

TEST(addition, big_number_test) {
  MYMatrix matrix_check(999, 1999);
  ASSERT_NEAR(matrix_check(998, 1998), 0, 1e-7);
}

TEST(throw_test, mul_number_matrix_test) {
  MYMatrix matrix_1(2, 2), matrix_2(2, 2);
  double count = 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      matrix_1(i, j) = count;
      count++;
    }
  }
  matrix_1 = 2 * matrix_1;
  matrix_2(0, 0) = 2;
  matrix_2(0, 1) = 4;
  matrix_2(1, 0) = 6;
  matrix_2(1, 1) = 8;
  EXPECT_TRUE(matrix_1.EqMatrix(matrix_2));
}

TEST(operator_overloading, operator_index) {
  const MYMatrix matrix_1(2, 2);
  const double x = matrix_1(1, 0);
  EXPECT_TRUE(x == 0);
  EXPECT_THROW(matrix_1(3, 0), std::logic_error);
  EXPECT_ANY_THROW(matrix_1(0, -3));
}

TEST(sega, operator_index) {
  MYMatrix matrix_1;
  EXPECT_THROW(matrix_1(0, 0), std::logic_error);
}

TEST(TestChain, TestChain1) {
  MYMatrix matrix1(1, 1);
  MYMatrix matrix2(2, 2);
  MYMatrix matrix3(3, 3);

  EXPECT_EQ((matrix1 = matrix2 = matrix3).get_cols(), matrix3.get_cols());
  EXPECT_TRUE(matrix1 == matrix3);
}

TEST(TestChain, TestChain2) {
  MYMatrix matrix1{1, 1};
  MYMatrix matrix2{2, 2};
  MYMatrix matrix3{3, 3};

  auto size3 = matrix3.get_cols();

  EXPECT_EQ((matrix1 = std::move(matrix2) = std::move(matrix3)).get_cols(),
            size3);
  EXPECT_FALSE(matrix1 == matrix3);
}

TEST(TestChain, TestChain3) {
  MYMatrix matrix1{1, 1};
  MYMatrix matrix2{1, 1};
  MYMatrix matrix3{1, 1};
  matrix1(0, 0) = 1.0;
  matrix2(0, 0) = 2.0;
  matrix3(0, 0) = 3.0;

  EXPECT_EQ((matrix1 += matrix2 += matrix3)(0, 0), 6.0);
  EXPECT_EQ(matrix1(0, 0), 6.0);
}

TEST(TestChain, TestChain4) {
  MYMatrix matrix1{1, 1};
  MYMatrix matrix2{1, 1};
  MYMatrix matrix3{1, 1};
  matrix1(0, 0) = 1.0;
  matrix2(0, 0) = 2.0;
  matrix3(0, 0) = 3.0;

  EXPECT_EQ((matrix1 -= matrix2 -= matrix3)(0, 0), 2.0);
  EXPECT_EQ(matrix1(0, 0), 2.0);
}

TEST(TestChain, TestChain5) {
  MYMatrix matrix1{1, 1};
  MYMatrix matrix2{1, 1};
  MYMatrix matrix3{1, 1};
  matrix1(0, 0) = 1.0;
  matrix2(0, 0) = 2.0;
  matrix3(0, 0) = 3.0;

  EXPECT_EQ((matrix1 *= matrix2 *= matrix3)(0, 0), 6.0);
  EXPECT_EQ(matrix1(0, 0), 6.0);
}

TEST(TestConstructor, TestConstructor1) {
  MYMatrix matrix(0, 3);

  EXPECT_EQ(matrix.get_rows(), 0);
  EXPECT_EQ(matrix.get_cols(), 3);

  MYMatrix matrix_copy = matrix;
  EXPECT_EQ(matrix_copy.get_rows(), 0);
  EXPECT_EQ(matrix_copy.get_cols(), 3);
  EXPECT_TRUE(matrix_copy == matrix);

  MYMatrix matrix1(3, 3);
  matrix1 = matrix;
  EXPECT_EQ(matrix1.get_rows(), 0);
  EXPECT_EQ(matrix1.get_cols(), 3);
  EXPECT_TRUE(matrix1 == matrix);

  MYMatrix matrix_move = std::move(matrix);
  EXPECT_EQ(matrix_move.get_rows(), 0);
  EXPECT_EQ(matrix_move.get_cols(), 3);
  EXPECT_TRUE(matrix_move == matrix_copy);

  MYMatrix matrix2(3, 3);
  matrix2 = std::move(matrix_copy);
  EXPECT_EQ(matrix2.get_rows(), 0);
  EXPECT_EQ(matrix2.get_cols(), 3);
  EXPECT_TRUE(matrix2 == matrix_move);
}

TEST(TestConstructor, TestConstructor2) {
  MYMatrix matrix(3, 0);

  EXPECT_EQ(matrix.get_rows(), 3);
  EXPECT_EQ(matrix.get_cols(), 0);

  MYMatrix matrix_copy = matrix;
  EXPECT_EQ(matrix_copy.get_rows(), 3);
  EXPECT_EQ(matrix_copy.get_cols(), 0);
  EXPECT_TRUE(matrix_copy == matrix);

  MYMatrix matrix1(3, 3);
  matrix1 = matrix;
  EXPECT_EQ(matrix1.get_rows(), 3);
  EXPECT_EQ(matrix1.get_cols(), 0);
  EXPECT_TRUE(matrix1 == matrix);

  MYMatrix matrix_move = std::move(matrix);
  EXPECT_EQ(matrix_move.get_rows(), 3);
  EXPECT_EQ(matrix_move.get_cols(), 0);
  EXPECT_TRUE(matrix_move == matrix_copy);

  MYMatrix matrix2(3, 3);
  matrix2 = std::move(matrix_copy);
  EXPECT_EQ(matrix2.get_rows(), 3);
  EXPECT_EQ(matrix2.get_cols(), 0);
  EXPECT_TRUE(matrix2 == matrix_move);
}

TEST(TestConstructor, TestConstructor3) {
  MYMatrix matrix(0, 0);

  EXPECT_EQ(matrix.get_rows(), 0);
  EXPECT_EQ(matrix.get_cols(), 0);

  MYMatrix matrix_copy = matrix;
  EXPECT_EQ(matrix_copy.get_rows(), 0);
  EXPECT_EQ(matrix_copy.get_cols(), 0);
  EXPECT_TRUE(matrix_copy == matrix);

  MYMatrix matrix1(3, 3);
  matrix1 = matrix;
  EXPECT_EQ(matrix1.get_rows(), 0);
  EXPECT_EQ(matrix1.get_cols(), 0);
  EXPECT_TRUE(matrix1 == matrix);

  MYMatrix matrix_move = std::move(matrix);
  EXPECT_EQ(matrix_move.get_rows(), 0);
  EXPECT_EQ(matrix_move.get_cols(), 0);
  EXPECT_TRUE(matrix_move == matrix_copy);

  MYMatrix matrix2(3, 3);
  matrix2 = std::move(matrix_copy);
  EXPECT_EQ(matrix2.get_rows(), 0);
  EXPECT_EQ(matrix2.get_cols(), 0);
  EXPECT_TRUE(matrix2 == matrix_move);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты равенства
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestEmpty, TestEq1) {
  EXPECT_TRUE(MYMatrix(3, 0) == MYMatrix(3, 0));
  EXPECT_TRUE(MYMatrix(1, 0) == MYMatrix(1, 0));
  EXPECT_TRUE(MYMatrix(0, 1) == MYMatrix(0, 1));
  EXPECT_TRUE(MYMatrix(0, 3) == MYMatrix(0, 3));
  EXPECT_FALSE(MYMatrix(0, 3) == MYMatrix(3, 0));
  EXPECT_FALSE(MYMatrix(1, 0) == MYMatrix(0, 1));
  EXPECT_FALSE(MYMatrix(0, 3) == MYMatrix(0, 2));
  EXPECT_FALSE(MYMatrix(2, 0) == MYMatrix(1, 0));
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты мутаторов (сеттеров)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestEmpty, TestMutators1) {
  MYMatrix test_matrix{2, 2};
  MYMatrix check{0, 2};

  EXPECT_NO_THROW(test_matrix.SetRows(0));
  EXPECT_TRUE(test_matrix == check);
}

TEST(TestEmpty, TestMutators2) {
  MYMatrix test_matrix{2, 2};
  MYMatrix check{2, 0};

  EXPECT_NO_THROW(test_matrix.SetCols(0));
  EXPECT_TRUE(test_matrix == check);
}

TEST(TestEmpty, TestMutators3) {
  MYMatrix test_matrix(2, 3);
  MYMatrix check{0, 3};

  EXPECT_NO_THROW(test_matrix.SetRows(0));
  EXPECT_TRUE(test_matrix == check);
}

TEST(TestEmpty, TestMutators4) {
  MYMatrix test_matrix(2, 3);
  MYMatrix check{2, 0};

  EXPECT_NO_THROW(test_matrix.SetCols(0));
  EXPECT_TRUE(test_matrix == check);
}

TEST(TestCalcComplements, TestCalcComplementsException1) {
  MYMatrix test_matrix(2, 3);
  MYMatrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.CalcComplements());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplementsException2) {
  MYMatrix test_matrix(3, 2);

  EXPECT_EQ(test_matrix.get_rows(), 3);
  EXPECT_EQ(test_matrix.get_cols(), 2);

  MYMatrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.CalcComplements());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplementsException3) {
  MYMatrix test_matrix(1, 5);

  EXPECT_EQ(test_matrix.get_rows(), 1);
  EXPECT_EQ(test_matrix.get_cols(), 5);

  MYMatrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.CalcComplements());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplementsException4) {
  MYMatrix test_matrix(5, 1);

  EXPECT_EQ(test_matrix.get_rows(), 5);
  EXPECT_EQ(test_matrix.get_cols(), 1);

  MYMatrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.CalcComplements());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplementsZero1) {
  MYMatrix matrix1{3, 3};
  EXPECT_EQ(matrix1.get_cols(), 3);
  EXPECT_EQ(matrix1.get_rows(), 3);

  MYMatrix result_check{3, 3};
  EXPECT_EQ(result_check.get_cols(), 3);
  EXPECT_EQ(result_check.get_rows(), 3);

  matrix1(0, 0) = -3.00;
  matrix1(0, 1) = 6.00;
  matrix1(0, 2) = -3.00;
  matrix1(1, 0) = 6.00;
  matrix1(1, 1) = -12.00;
  matrix1(1, 2) = 6.00;
  matrix1(2, 0) = -3.00;
  matrix1(2, 1) = 6.00;
  matrix1(2, 2) = -3.00;

  MYMatrix matrix_before = matrix1;
  MYMatrix result = matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplementsZero2) {
  MYMatrix matrix1{3, 3};
  EXPECT_EQ(matrix1.get_cols(), 3);
  EXPECT_EQ(matrix1.get_rows(), 3);

  MYMatrix result_check{3, 3};
  EXPECT_EQ(result_check.get_cols(), 3);
  EXPECT_EQ(result_check.get_rows(), 3);

  MYMatrix matrix_before = matrix1;
  MYMatrix result = matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplementsZero3) {
  MYMatrix matrix1{3, 3};
  EXPECT_EQ(matrix1.get_cols(), 3);
  EXPECT_EQ(matrix1.get_rows(), 3);

  MYMatrix result_check{3, 3};
  EXPECT_EQ(result_check.get_cols(), 3);
  EXPECT_EQ(result_check.get_rows(), 3);

  matrix1(0, 0) = 0.00;
  matrix1(0, 1) = 9.00;
  matrix1(0, 2) = 0.0;
  matrix1(1, 0) = 0.00;
  matrix1(1, 1) = -12.00;
  matrix1(1, 2) = 0.0;
  matrix1(2, 0) = 0.00;
  matrix1(2, 1) = 7.00;
  matrix1(2, 2) = 0.00;

  MYMatrix matrix_before = matrix1;
  MYMatrix result = matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplementsZero4) {
  MYMatrix matrix1{4, 4};
  EXPECT_EQ(matrix1.get_cols(), 4);
  EXPECT_EQ(matrix1.get_rows(), 4);

  MYMatrix result_check{4, 4};
  EXPECT_EQ(result_check.get_cols(), 4);
  EXPECT_EQ(result_check.get_rows(), 4);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 15;
  matrix1(0, 2) = 1;
  matrix1(0, 3) = 1;
  matrix1(1, 0) = 2;
  matrix1(1, 1) = 16;
  matrix1(1, 2) = 2;
  matrix1(1, 3) = 2;
  matrix1(2, 0) = 3;
  matrix1(2, 1) = 17;
  matrix1(2, 2) = 3;
  matrix1(2, 3) = 3;
  matrix1(3, 0) = 4;
  matrix1(3, 1) = 18;
  matrix1(3, 2) = 4;
  matrix1(3, 3) = 4;

  MYMatrix matrix_before = matrix1;
  MYMatrix result = matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplementsZero5) {
  MYMatrix matrix1{4, 4};
  EXPECT_EQ(matrix1.get_cols(), 4);
  EXPECT_EQ(matrix1.get_rows(), 4);

  MYMatrix result_check{4, 4};
  EXPECT_EQ(result_check.get_cols(), 4);
  EXPECT_EQ(result_check.get_rows(), 4);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 5;
  matrix1(0, 2) = 9;
  matrix1(0, 3) = 13;
  matrix1(1, 0) = 2;
  matrix1(1, 1) = 6;
  matrix1(1, 2) = 10;
  matrix1(1, 3) = 14;
  matrix1(2, 0) = 3;
  matrix1(2, 1) = 7;
  matrix1(2, 2) = 11;
  matrix1(2, 3) = 15;
  matrix1(3, 0) = 4;
  matrix1(3, 1) = 8;
  matrix1(3, 2) = 12;
  matrix1(3, 3) = 16;

  MYMatrix matrix_before = matrix1;
  MYMatrix result = matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты на обычные матрицы
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestCalcComplements, TestCalcComplements1) {
  MYMatrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  MYMatrix result_check{2, 2};
  EXPECT_EQ(result_check.get_cols(), 2);
  EXPECT_EQ(result_check.get_rows(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  result_check(0, 0) = 4;
  result_check(0, 1) = -3;
  result_check(1, 0) = -2;
  result_check(1, 1) = 1;

  MYMatrix matrix_before = matrix1;
  MYMatrix result = matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplements2) {
  MYMatrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  MYMatrix result_check{2, 2};
  EXPECT_EQ(result_check.get_cols(), 2);
  EXPECT_EQ(result_check.get_rows(), 2);

  matrix1(0, 0) = 12.452;
  matrix1(0, 1) = 3.34245;
  matrix1(1, 0) = 3.356;
  matrix1(1, 1) = 3.543;

  result_check(0, 0) = 3.543;
  result_check(0, 1) = -3.356;
  result_check(1, 0) = -3.34245;
  result_check(1, 1) = 12.452;

  MYMatrix matrix_before = matrix1;
  MYMatrix result = matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplements3) {
  MYMatrix matrix1{3, 3};
  EXPECT_EQ(matrix1.get_cols(), 3);
  EXPECT_EQ(matrix1.get_rows(), 3);

  MYMatrix result_check{3, 3};
  EXPECT_EQ(result_check.get_cols(), 3);
  EXPECT_EQ(result_check.get_rows(), 3);

  matrix1(0, 0) = 1;
  matrix1(1, 0) = 2;
  matrix1(2, 0) = 3;
  matrix1(0, 1) = 4;
  matrix1(1, 1) = 5;
  matrix1(2, 1) = 6;
  matrix1(0, 2) = 7;
  matrix1(1, 2) = 8;
  matrix1(2, 2) = 9;

  result_check(0, 0) = -3;
  result_check(1, 0) = 6;
  result_check(2, 0) = -3;
  result_check(0, 1) = 6;
  result_check(1, 1) = -12;
  result_check(2, 1) = 6;
  result_check(0, 2) = -3;
  result_check(1, 2) = 6;
  result_check(2, 2) = -3;

  MYMatrix matrix_before = matrix1;
  MYMatrix result = matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplements4) {
  MYMatrix matrix1{4, 4};
  EXPECT_EQ(matrix1.get_cols(), 4);
  EXPECT_EQ(matrix1.get_rows(), 4);

  MYMatrix result_check{4, 4};
  EXPECT_EQ(result_check.get_cols(), 4);
  EXPECT_EQ(result_check.get_rows(), 4);

  matrix1(0, 0) = -3.86;
  matrix1(1, 0) = -8.48;
  matrix1(2, 0) = -8.36;
  matrix1(3, 0) = 2.82;
  matrix1(0, 1) = 7.02;
  matrix1(1, 1) = 7.17;
  matrix1(2, 1) = -4.87;
  matrix1(3, 1) = -1.54;
  matrix1(0, 2) = 4.23;
  matrix1(1, 2) = 7.84;
  matrix1(2, 2) = 3.56;
  matrix1(3, 2) = -8.62;
  matrix1(0, 3) = 4.82;
  matrix1(1, 3) = -7.78;
  matrix1(2, 3) = 3.62;
  matrix1(3, 3) = 3.71;

  result_check(0, 0) = 11781393.0 / 250000.0;
  result_check(1, 0) = -593383083.0 / 1000000.0;
  result_check(2, 0) = -113629541.0 / 200000.0;
  result_check(3, 0) = -187801277.0 / 250000.0;
  result_check(0, 1) = 3349777.0 / 6250.0;
  result_check(1, 1) = 1886893.0 / 6250.0;
  result_check(2, 1) = -108158171.0 / 250000.0;
  result_check(3, 1) = 44864781.0 / 125000.0;
  result_check(0, 2) = 48626797.0 / 250000.0;
  result_check(1, 2) = -46586467.0 / 100000.0;
  result_check(2, 2) = -2410461.0 / 100000.0;
  result_check(3, 2) = -18845574.0 / 15625.0;
  result_check(0, 3) = 39911437.0 / 62500.0;
  result_check(1, 3) = -253030017.0 / 500000.0;
  result_check(2, 3) = 98132137.0 / 500000.0;
  result_check(3, 3) = -16461827.0 / 250000.0;

  MYMatrix matrix_before = matrix1;
  MYMatrix result = matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplements5) {
  MYMatrix matrix1{5, 5};
  EXPECT_EQ(matrix1.get_cols(), 5);
  EXPECT_EQ(matrix1.get_rows(), 5);

  MYMatrix result_check{5, 5};
  EXPECT_EQ(result_check.get_cols(), 5);
  EXPECT_EQ(result_check.get_rows(), 5);

  matrix1(0, 0) = 3.3402;
  matrix1(0, 1) = -7.8838;
  matrix1(0, 2) = 1.4603;
  matrix1(0, 3) = -1.3716;
  matrix1(0, 4) = 6.0723;
  matrix1(1, 0) = -7.8846;
  matrix1(1, 1) = 7.8416;
  matrix1(1, 2) = -4.2679;
  matrix1(1, 3) = 9.8356;
  matrix1(1, 4) = -2.3961;
  matrix1(2, 0) = 4.1176;
  matrix1(2, 1) = 2.0162;
  matrix1(2, 2) = 4.7337;
  matrix1(2, 3) = 6.3434;
  matrix1(2, 4) = -9.7277;
  matrix1(3, 0) = -7.4141;
  matrix1(3, 1) = -6.0886;
  matrix1(3, 2) = 3.0417;
  matrix1(3, 3) = 4.7122;
  matrix1(3, 4) = 3.8023;
  matrix1(4, 0) = -2.4891;
  matrix1(4, 1) = -5.7155;
  matrix1(4, 2) = -1.7409;
  matrix1(4, 3) = -5.2048;
  matrix1(4, 4) = -6.8199;

  result_check(0, 0) = -1465690149213583.0 / 152587890625;
  result_check(0, 1) = 1272307326797681.0 / 122070312500;
  result_check(0, 2) = 8908235542058123.0 / 610351562500;
  result_check(0, 3) = -3051493103944107.0 / 305175781250;
  result_check(0, 4) = -6463308694007859.0 / 4882812500000;
  result_check(1, 0) = -1311111307169479.0 / 610351562500;
  result_check(1, 1) = 4013698343237797.0 / 1220703125000;
  result_check(1, 2) = 1879307039061624.0 / 152587890625;
  result_check(1, 3) = -2346277736890227.0 / 305175781250;
  result_check(1, 4) = 918022536110711.0 / 1220703125000;
  result_check(2, 0) = -2046840259044663.0 / 610351562500;
  result_check(2, 1) = 4228464572521883.0 / 2441406250000;
  result_check(2, 2) = -6621800960129521.0 / 2441406250000;
  result_check(2, 3) = -2641705482122563.0 / 610351562500;
  result_check(2, 4) = 7359340653769.0 / 1953125000;
  result_check(3, 0) = 4563655460607809.0 / 610351562500;
  result_check(3, 1) = 431856638931077.0 / 1953125000000;
  result_check(3, 2) = -6291617971140427.0 / 610351562500;
  result_check(3, 3) = 1313171371096307.0 / 1220703125000;
  result_check(3, 4) = -5390167833396221.0 / 4882812500000;
  result_check(4, 0) = 2817957903551703.0 / 2441406250000;
  result_check(4, 1) = 3526500249653419.0 / 610351562500;
  result_check(4, 2) = 414413005838107.0 / 61035156250;
  result_check(4, 3) = 348820831855181.0 / 610351562500;
  result_check(4, 4) = 327320067348047.0 / 61035156250;

  MYMatrix matrix_before = matrix1;
  MYMatrix result = matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestConstructor, TestConstructorException1) {
  EXPECT_ANY_THROW(MYMatrix(-1, 99));
}

TEST(TestConstructor, TestConstructorException2) {
  EXPECT_ANY_THROW(MYMatrix(99, -1));
}

TEST(TestConstructor, TestConstructorException3) {
  EXPECT_ANY_THROW(MYMatrix(-1, -1));
}

TEST(TestConstructor, TestConstructorException4) {
  EXPECT_ANY_THROW(MYMatrix(-99, -99));
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты успешного создания объектов
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestConstructor, TestConstructorParams1) {
  MYMatrix matrix_check(5, 4);
  EXPECT_EQ(matrix_check.get_rows(), 5);
  EXPECT_EQ(matrix_check.get_cols(), 4);
}

TEST(TestConstructor, TestConstructorParams2) {
  MYMatrix matrix_check(999, 1999);
  EXPECT_EQ(matrix_check.get_rows(), 999);
  EXPECT_EQ(matrix_check.get_cols(), 1999);
}

TEST(TestConstructor, TestConstructorCopy1) {
  MYMatrix matrix_check = MYMatrix(2, 2);

  matrix_check(0, 0) = 4.0;
  matrix_check(0, 1) = 4.0;
  matrix_check(1, 0) = 4.0;
  matrix_check(1, 1) = 4.0;

  MYMatrix matrix_copy = matrix_check;

  EXPECT_EQ(matrix_check.get_cols(), 2);
  EXPECT_EQ(matrix_check.get_rows(), 2);

  EXPECT_EQ(matrix_copy.get_cols(), 2);
  EXPECT_EQ(matrix_copy.get_rows(), 2);
}

TEST(TestConstructor, TestConstructorCopy2) {
  MYMatrix matrix_check = MYMatrix(2, 2);

  matrix_check(0, 0) = 4.0;
  matrix_check(0, 1) = 4.0;
  matrix_check(1, 0) = 4.0;
  matrix_check(1, 1) = 4.0;

  MYMatrix matrix_copy(matrix_check);

  EXPECT_EQ(matrix_check.get_cols(), 2);
  EXPECT_EQ(matrix_check.get_rows(), 2);

  EXPECT_EQ(matrix_copy.get_cols(), 2);
  EXPECT_EQ(matrix_copy.get_rows(), 2);
}

TEST(TestConstructor, TestConstructorMove2) {
  MYMatrix matrix_test{14, 14};

  MYMatrix matrix_check = std::move(matrix_test);

  EXPECT_EQ(matrix_check.get_cols(), 14);
  EXPECT_EQ(matrix_check.get_rows(), 14);
  EXPECT_EQ(matrix_test.get_rows(), 0);
  EXPECT_EQ(matrix_test.get_rows(), 0);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты операторов присваивания
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestConstructor, TestAssignmentCopy) {
  MYMatrix matrix_test{5, 5};
  MYMatrix matrix_check{2, 2};

  matrix_check = matrix_test;

  EXPECT_EQ(matrix_check.get_cols(), 5);
  EXPECT_EQ(matrix_check.get_rows(), 5);
  EXPECT_EQ(matrix_test.get_rows(), 5);
  EXPECT_EQ(matrix_test.get_rows(), 5);
}

TEST(TestConstructor, TestAssignmentMove2) {
  MYMatrix matrix_test{5, 5};
  MYMatrix matrix_check{2, 2};

  matrix_check = std::move(matrix_test);

  EXPECT_EQ(matrix_check.get_cols(), 5);
  EXPECT_EQ(matrix_check.get_rows(), 5);
  EXPECT_EQ(matrix_test.get_rows(), 0);
  EXPECT_EQ(matrix_test.get_rows(), 0);
}

TEST(TestDeterminant, TestDeterminantException1) {
  MYMatrix test_matrix(2, 3);
  MYMatrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.Determinant());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestDeterminant, TestDeterminantException2) {
  MYMatrix test_matrix(3, 2);
  MYMatrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.Determinant());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestDeterminant, TestDeterminantException3) {
  MYMatrix test_matrix(55, 2);
  MYMatrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.Determinant());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestDeterminant, TestDeterminantException4) {
  MYMatrix test_matrix(3, 55);
  MYMatrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.Determinant());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero2) {
  MYMatrix matrix1{3, 3};
  EXPECT_EQ(matrix1.get_cols(), 3);
  EXPECT_EQ(matrix1.get_rows(), 3);

  matrix1(0, 0) = 1.1;
  matrix1(0, 1) = 1.2;
  matrix1(0, 2) = 1.3;
  matrix1(1, 0) = 1.4;
  matrix1(1, 1) = 1.5;
  matrix1(1, 2) = 1.6;
  matrix1(2, 0) = 1.7;
  matrix1(2, 1) = 1.8;
  matrix1(2, 2) = 1.9;

  double result_check = 0.0;
  MYMatrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero3) {
  MYMatrix matrix1{3, 3};
  EXPECT_EQ(matrix1.get_cols(), 3);
  EXPECT_EQ(matrix1.get_rows(), 3);

  matrix1(0, 0) = -66;
  matrix1(0, 1) = -66;
  matrix1(0, 2) = -66;
  matrix1(1, 0) = -66;
  matrix1(1, 1) = -66;
  matrix1(1, 2) = -66;
  matrix1(2, 0) = -66;
  matrix1(2, 1) = -66;
  matrix1(2, 2) = -66;

  double result_check = 0.0;
  MYMatrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminant1) {
  MYMatrix matrix1{1, 1};
  EXPECT_EQ(matrix1.get_cols(), 1);
  EXPECT_EQ(matrix1.get_rows(), 1);

  matrix1(0, 0) = 1.5;

  double result_check = 1.5;
  MYMatrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminant2) {
  MYMatrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  matrix1(0, 0) = 1.1;
  matrix1(0, 1) = 1.2;
  matrix1(1, 0) = 1.3;
  matrix1(1, 1) = 1.4;

  double result_check = -0.02;
  MYMatrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminant3) {
  MYMatrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  matrix1(0, 0) = 7.72122069261968;
  matrix1(1, 0) = -7.3629210004583;
  matrix1(0, 1) = 8.93235725676641;
  matrix1(1, 1) = 2.69165195827372;

  double result_check = 86.5510796270;
  MYMatrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminant4) {
  MYMatrix matrix1{3, 3};
  EXPECT_EQ(matrix1.get_cols(), 3);
  EXPECT_EQ(matrix1.get_rows(), 3);

  matrix1(0, 0) = 0;
  matrix1(0, 1) = 1;
  matrix1(0, 2) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;
  matrix1(1, 2) = 5;
  matrix1(2, 0) = 6;
  matrix1(2, 1) = 0;
  matrix1(2, 2) = 7;

  double result_check = -39;
  MYMatrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminant5) {
  MYMatrix matrix1{3, 3};
  EXPECT_EQ(matrix1.get_cols(), 3);
  EXPECT_EQ(matrix1.get_rows(), 3);

  matrix1(0, 0) = 5.34922476788051;
  matrix1(1, 0) = 1.65522041497752;
  matrix1(2, 0) = -8.68382598599419;
  matrix1(0, 1) = -3.25669884728268;
  matrix1(1, 1) = 10.8967615629081;
  matrix1(2, 1) = 4.55130848893896;
  matrix1(0, 2) = -2.14478276530281;
  matrix1(1, 2) = -2.7382052554749;
  matrix1(2, 2) = 5.7808097708039;

  double result_check = 138.2380038449;
  MYMatrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestInverse, TestInverseException1) {
  MYMatrix test_matrix(2, 3);
  MYMatrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.InverseMatrix());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestInverse, TestInverseException2) {
  MYMatrix test_matrix(3, 2);
  MYMatrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.InverseMatrix());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestInverse, TestInverseException3) {
  MYMatrix test_matrix(1, 5);
  MYMatrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.InverseMatrix());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestInverse, TestInverseException4) {
  MYMatrix test_matrix(5, 1);
  MYMatrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.InverseMatrix());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestInverse, TestInverseZero1) {
  MYMatrix matrix1{1, 1};
  EXPECT_EQ(matrix1.get_cols(), 1);
  EXPECT_EQ(matrix1.get_rows(), 1);

  matrix1(0, 0) = 0.0;

  MYMatrix matrix_before = matrix1;

  EXPECT_ANY_THROW(matrix1.InverseMatrix());
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestInverse, TestInverseZero2) {
  MYMatrix matrix1{3, 3};
  EXPECT_EQ(matrix1.get_cols(), 3);
  EXPECT_EQ(matrix1.get_rows(), 3);

  matrix1(0, 0) = 1.1;
  matrix1(0, 1) = 12;
  matrix1(0, 2) = 0.0;
  matrix1(1, 0) = 14;
  matrix1(1, 1) = 1.5;
  matrix1(1, 2) = 0.0;
  matrix1(2, 0) = 1.7;
  matrix1(2, 1) = 18;
  matrix1(2, 2) = 0.0;

  MYMatrix matrix_before = matrix1;

  EXPECT_ANY_THROW(matrix1.InverseMatrix());
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestInverse, TestInverseZero3) {
  MYMatrix matrix1{3, 3};
  EXPECT_EQ(matrix1.get_cols(), 3);
  EXPECT_EQ(matrix1.get_rows(), 3);

  matrix1(0, 0) = 1.1;
  matrix1(0, 1) = 1.2;
  matrix1(0, 2) = 1.3;
  matrix1(1, 0) = 1.4;
  matrix1(1, 1) = 1.5;
  matrix1(1, 2) = 1.6;
  matrix1(2, 0) = 1.7;
  matrix1(2, 1) = 1.8;
  matrix1(2, 2) = 1.9;

  MYMatrix matrix_before = matrix1;

  EXPECT_ANY_THROW(matrix1.InverseMatrix());
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestInverse, TestInverseZero4) {
  MYMatrix matrix1{3, 3};
  EXPECT_EQ(matrix1.get_cols(), 3);
  EXPECT_EQ(matrix1.get_rows(), 3);

  matrix1(0, 0) = -66;
  matrix1(0, 1) = -66;
  matrix1(0, 2) = -66;
  matrix1(1, 0) = -66;
  matrix1(1, 1) = -66;
  matrix1(1, 2) = -66;
  matrix1(2, 0) = -66;
  matrix1(2, 1) = -66;
  matrix1(2, 2) = -66;

  MYMatrix matrix_before = matrix1;

  EXPECT_ANY_THROW(matrix1.InverseMatrix());
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestInverse, TestInverse6) {
  MYMatrix matrix1{5, 5};
  EXPECT_EQ(matrix1.get_cols(), 5);
  EXPECT_EQ(matrix1.get_rows(), 5);

  MYMatrix check_inverse_matrix{5, 5};
  EXPECT_EQ(check_inverse_matrix.get_cols(), 5);
  EXPECT_EQ(check_inverse_matrix.get_rows(), 5);

  matrix1(0, 0) = 54.5;
  matrix1(0, 1) = 255.5;
  matrix1(0, 2) = 24.5;
  matrix1(0, 3) = 23.5;
  matrix1(0, 4) = 0.0;
  matrix1(1, 0) = 523.3;
  matrix1(1, 1) = 534.2;
  matrix1(1, 2) = 342.4;
  matrix1(1, 3) = 0.0;
  matrix1(1, 4) = 532.3;
  matrix1(2, 0) = 543.2;
  matrix1(2, 1) = 34.3;
  matrix1(2, 2) = 0.0;
  matrix1(2, 3) = 241.3;
  matrix1(2, 4) = 3423.4;
  matrix1(3, 0) = 3625.2;
  matrix1(3, 1) = 0.0;
  matrix1(3, 2) = 3244.0;
  matrix1(3, 3) = 24.4;
  matrix1(3, 4) = 4365.2;
  matrix1(4, 0) = 0.0;
  matrix1(4, 1) = 231.2;
  matrix1(4, 2) = 2314.2;
  matrix1(4, 3) = 1234.1;
  matrix1(4, 4) = 213.2;

  check_inverse_matrix(0, 0) = 8441832269136.3 / 1.2952183794233E+14;
  check_inverse_matrix(0, 1) = -3963589030994.7 / 1.2952183794233E+14;
  check_inverse_matrix(0, 2) = 17086706405.892 / 1.2952183794233E+14;
  check_inverse_matrix(0, 3) = 478403017840.19 / 1.2952183794233E+14;
  check_inverse_matrix(0, 4) = -173550858290.05 / 1.2952183794233E+14;
  check_inverse_matrix(1, 0) = -1860988589140.3 / 1.2952183794233E+14;
  check_inverse_matrix(1, 1) = 1115918880674.1 / 1.2952183794233E+14;
  check_inverse_matrix(1, 2) = -7728325041.456 / 1.2952183794233E+14;
  check_inverse_matrix(1, 3) = -131948153477.35 / 1.2952183794233E+14;
  check_inverse_matrix(1, 4) = 39557257614.576 / 1.2952183794233E+14;
  check_inverse_matrix(2, 0) = -6523983407620.5 / 1.2952183794233E+14;
  check_inverse_matrix(2, 1) = 3062517351997 / 1.2952183794233E+14;
  check_inverse_matrix(2, 2) = -57361768020.684 / 1.2952183794233E+14;
  check_inverse_matrix(2, 3) = -335401997736.92 / 1.2952183794233E+14;
  check_inverse_matrix(2, 4) = 142078286562.88 / 1.2952183794233E+14;
  check_inverse_matrix(3, 0) = 12968602437721 / 1.2952183794233E+14;
  check_inverse_matrix(3, 1) = -6133333912636.1 / 1.2952183794233E+14;
  check_inverse_matrix(3, 2) = 104201058105.43 / 1.2952183794233E+14;
  check_inverse_matrix(3, 3) = 674771816413.93 / 1.2952183794233E+14;
  check_inverse_matrix(3, 4) = -175713853808.82 / 1.2952183794233E+14;
  check_inverse_matrix(4, 0) = -2234940453411.7 / 1.2952183794233E+14;
  check_inverse_matrix(4, 1) = 1050043528991.2 / 1.2952183794233E+14;
  check_inverse_matrix(4, 2) = 27855846600.084 / 1.2952183794233E+14;
  check_inverse_matrix(4, 3) = -122149073122.39 / 1.2952183794233E+14;
  check_inverse_matrix(4, 4) = 39526717652.346 / 1.2952183794233E+14;

  MYMatrix matrix_before = matrix1;
  MYMatrix matrix_inverse = matrix1.InverseMatrix();

  EXPECT_TRUE(matrix_inverse == check_inverse_matrix);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestMutators, TestMutatorsException1) {
  MYMatrix test_matrix(2, 3);
  MYMatrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.SetRows(-1));
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestMutators, TestMutatorsException2) {
  MYMatrix test_matrix(3, 2);
  MYMatrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.SetRows(-1));
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestMutators, TestMutatorsException3) {
  MYMatrix test_matrix(2, 3);
  MYMatrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.SetCols(-1));
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestMutators, TestMutatorsException4) {
  MYMatrix test_matrix(3, 2);
  MYMatrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.SetCols(-1));
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestMutators, TestMutatorsException5) {
  MYMatrix test_matrix(2, 2);
  MYMatrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.SetCols(-9999));
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestMutators, TestMutatorsException6) {
  MYMatrix test_matrix(3, 2);
  MYMatrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.SetCols(-9999));
  EXPECT_TRUE(test_matrix == matrix_before);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestMutators, TestMutators8) {
  MYMatrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix1.SetRows(1);

  EXPECT_EQ(matrix1.get_rows(), 1);
  EXPECT_EQ(matrix1.get_cols(), 2);

  EXPECT_NEAR(matrix1(0, 0), 1, 1e-7);
  EXPECT_NEAR(matrix1(0, 1), 2, 1e-7);
}

TEST(TestMutators, TestMutators9) {
  MYMatrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix1.SetCols(1);

  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 1);

  EXPECT_NEAR(matrix1(0, 0), 1, 1e-7);
  EXPECT_NEAR(matrix1(1, 0), 3, 1e-7);
}

TEST(TestMutators, TestMutators10) {
  MYMatrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix1.SetRows(3);

  EXPECT_EQ(matrix1.get_rows(), 3);
  EXPECT_EQ(matrix1.get_cols(), 2);

  EXPECT_NEAR(matrix1(0, 0), 1, 1e-7);
  EXPECT_NEAR(matrix1(0, 1), 2, 1e-7);
  EXPECT_NEAR(matrix1(1, 0), 3, 1e-7);
  EXPECT_NEAR(matrix1(1, 1), 4, 1e-7);
  EXPECT_NEAR(matrix1(2, 0), 0, 1e-7);
  EXPECT_NEAR(matrix1(2, 1), 0, 1e-7);
}

TEST(TestMutators, TestMutators11) {
  MYMatrix matrix1{2, 2};
  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix1.SetCols(3);

  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 3);

  EXPECT_NEAR(matrix1(0, 0), 1, 1e-7);
  EXPECT_NEAR(matrix1(0, 1), 2, 1e-7);
  EXPECT_NEAR(matrix1(0, 2), 0, 1e-7);
  EXPECT_NEAR(matrix1(1, 0), 3, 1e-7);
  EXPECT_NEAR(matrix1(1, 1), 4, 1e-7);
  EXPECT_NEAR(matrix1(1, 2), 0, 1e-7);
}

TEST(TestDeterminant, TestDeterminantException6) {
  MYMatrix test_matrix(0, 0);
  MYMatrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.Determinant());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestEmpty, TestDeterminant1) {
  MYMatrix test_matrix(1, 0);
  MYMatrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.Determinant());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestEmpty, TestDeterminant2) {
  MYMatrix test_matrix(0, 1);
  MYMatrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.Determinant());
  EXPECT_TRUE(test_matrix == matrix_before);
}

int main() {
  testing::InitGoogleTest();
  int retval = RUN_ALL_TESTS();
  return retval;
}
