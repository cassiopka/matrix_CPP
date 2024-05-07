#ifndef MY_MATRIX_OOP_H
#define MY_MATRIX_OOP_H

#include <cmath>
#include <iostream>

class MYMatrix {
 private:
  // Attributes
  int rows_, cols_;  // Rows and columns
  double** matrix_;  // Pointer to the memory where the matrix is allocated
  const double min_diff = 0.0000001;

 public:
  // constructors and destructor
  MYMatrix() noexcept;
  MYMatrix(int rows, int cols);
  MYMatrix(const MYMatrix& other);
  MYMatrix(MYMatrix&& other) noexcept;
  ~MYMatrix();

  // accessors
  int GetRows() noexcept;
  int GetCols() noexcept;
  int get_rows() const noexcept;
  int get_cols() const noexcept;
  // mutators
  void SetRows(int rows);
  void SetCols(int cols);

  // operations
  bool EqMatrix(const MYMatrix& other) const;
  void SumMatrix(const MYMatrix& other);
  void SubMatrix(const MYMatrix& other);
  void MulNumber(const double num) noexcept;
  void MulMatrix(const MYMatrix& other);
  MYMatrix Transpose() const;
  MYMatrix CalcComplements() const;
  double Determinant() const;
  MYMatrix InverseMatrix() const;

  // operators
  MYMatrix operator+(const MYMatrix& other) const;
  MYMatrix operator-(const MYMatrix& other) const;
  MYMatrix operator*(const double number) const noexcept;
  MYMatrix operator*(const MYMatrix& other) const;
  bool operator==(const MYMatrix& other) const noexcept;
  // void operator=(MYMatrix& other);
  MYMatrix operator=(MYMatrix other);
  MYMatrix operator+=(const MYMatrix& other);
  MYMatrix operator-=(const MYMatrix& other);
  MYMatrix operator*=(const MYMatrix& other);
  MYMatrix operator*=(const double number) noexcept;
  double& operator()(const int i, const int j) const;
  // double& operator()(int i, int j) const;

  // helpers
  bool SameSize(const MYMatrix& other) noexcept;
  MYMatrix CreateMinor(int row, int col) const;
  void InsertArray(double* dum);
  void SetElem(int i, int j, double elem);
};

MYMatrix operator*(const double number, const MYMatrix& other) noexcept;

#endif  // MY_MATRIX_OOP_H
