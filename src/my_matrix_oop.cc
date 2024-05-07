#include "my_matrix_oop.h"

// constructors and destructor

MYMatrix::MYMatrix() noexcept {
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}

MYMatrix::MYMatrix(int rows, int cols) {
  if (rows < 0 || cols < 0)
    throw std::logic_error("Impossible size for matrix");
  rows_ = rows, cols_ = cols;

  matrix_ = new double*[rows_]();
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]();
  }
}

MYMatrix::MYMatrix(const MYMatrix& other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = new double*[rows_]();
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]();
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

MYMatrix::MYMatrix(MYMatrix&& other) noexcept {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;

  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

MYMatrix::~MYMatrix() {
  if (matrix_) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  }
  rows_ = 0;
  cols_ = 0;
}

// accessors

int MYMatrix::GetRows() noexcept { return rows_; }

int MYMatrix::get_rows() const noexcept { return rows_; }

int MYMatrix::GetCols() noexcept { return cols_; }

int MYMatrix::get_cols() const noexcept { return cols_; };

// mutators

void MYMatrix::SetRows(int rows) {
  if (rows >= 0) {
    double** buff = new double*[rows]();
    for (int i = 0; i < rows; i++) {
      buff[i] = new double[cols_]();
    }
    if (rows > rows_) {
      for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
          buff[i][j] = matrix_[i][j];
        }
      }
      for (int i = rows_; i < rows; i++) {
        for (int j = 0; j < cols_; j++) {
          buff[i][j] = 0;
        }
      }
    } else if (rows <= rows_) {
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols_; j++) {
          buff[i][j] = matrix_[i][j];
        }
      }
    }
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
    rows_ = rows;
    matrix_ = nullptr;
    matrix_ = std::move(buff);
  } else
    throw std::logic_error("Impossible value");
}

void MYMatrix::SetCols(int cols) {
  if (cols >= 0) {
    double** buff = new double*[rows_]();
    for (int i = 0; i < rows_; i++) {
      buff[i] = new double[cols]();
    }
    if (cols > cols_) {
      for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
          buff[i][j] = matrix_[i][j];
        }
        for (int j = cols_; j < cols; j++) {
          buff[i][j] = 0;
        }
      }
    } else if (cols <= cols_) {
      for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols; j++) {
          buff[i][j] = matrix_[i][j];
        }
      }
    }
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
    matrix_ = nullptr;
    cols_ = cols;
    matrix_ = std::move(buff);
  } else
    throw std::logic_error("Impossible value");
}

// operations

bool MYMatrix::EqMatrix(const MYMatrix& other) const {
  bool status = 1;
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    status = 0;
  }
  for (int i = 0; i < rows_ && status == 1; i++) {
    for (int j = 0; j < cols_ && status == 1; j++) {
      if (std::fabs(this->matrix_[i][j] - other.matrix_[i][j]) > min_diff) {
        status = 0;
      }
    }
  }
  return status;
}

void MYMatrix::SumMatrix(const MYMatrix& other) {
  if (!SameSize(other)) throw std::logic_error("Матрицы разного размера");
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void MYMatrix::SubMatrix(const MYMatrix& other) {
  if (!SameSize(other)) throw std::logic_error("Матрицы разного размера");
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void MYMatrix::MulNumber(const double num) noexcept {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}

void MYMatrix::MulMatrix(const MYMatrix& other) {
  if (cols_ != other.rows_) {
    throw std::logic_error("Matrix doesn't match");
  }
  MYMatrix buff(rows_, other.cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      buff.matrix_[i][j] = 0;
      for (int k = 0; k < cols_; k++)
        buff.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
    }
  }
  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
  matrix_ = nullptr;

  this->matrix_ = std::move(buff.matrix_);
  buff.matrix_ = nullptr;
  this->rows_ = buff.rows_;
  this->cols_ = buff.cols_;
}

MYMatrix MYMatrix::Transpose() const {
  MYMatrix buff(cols_, rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      buff.SetElem(j, i, (*this)(i, j));
    }
  }
  return buff;
}

MYMatrix MYMatrix::CalcComplements() const {
  if (rows_ != cols_ || rows_ == 1 || cols_ == 1)
    throw std::logic_error("Size of matrix doesn't match");

  MYMatrix complements(rows_, cols_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      MYMatrix minor = CreateMinor(i, j);
      complements.matrix_[i][j] = minor.Determinant() * pow(-1, i + j);
    }
  }

  return complements;
}

double MYMatrix::Determinant() const {
  double det = 0;
  if (rows_ != cols_) {
    throw std::logic_error("Matrix is not square");
  }

  if (rows_ == 1) {
    det = matrix_[0][0];
  } else if (rows_ == 2) {
    det = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  } else if (rows_ > 2) {
    for (int j = 0; j < cols_; j++) {
      MYMatrix minor = (*this).CreateMinor(0, j);
      det += minor.Determinant() * matrix_[0][j] * pow(-1, j);
    }
  } else {
    throw std::logic_error("Matrix isn't match");
  }
  return det;
}

MYMatrix MYMatrix::InverseMatrix() const {
  if (std::abs(Determinant()) < 1e-7) throw std::logic_error("Determinant = 0");

  MYMatrix inverse(rows_, cols_);

  if (rows_ == 1) {
    inverse.matrix_[0][0] = 1 / matrix_[0][0];
  } else {
    double det = Determinant();
    MYMatrix temp_complements(rows_, cols_);

    temp_complements = CalcComplements();
    inverse = temp_complements.Transpose();
    inverse.MulNumber(1 / det);
  }
  return inverse;
}

// operators

MYMatrix MYMatrix::operator+(const MYMatrix& other) const {
  MYMatrix buff(*this);
  buff.SumMatrix(other);
  return buff;
}

MYMatrix MYMatrix::operator-(const MYMatrix& other) const {
  MYMatrix buff(*this);
  buff.SubMatrix(other);
  return buff;
}

MYMatrix MYMatrix::operator*(const double number) const noexcept {
  MYMatrix buff(*this);
  buff.MulNumber(number);
  return buff;
}

MYMatrix MYMatrix::operator*(const MYMatrix& other) const {
  MYMatrix buff(*this);
  buff.MulMatrix(other);
  return buff;
}

bool MYMatrix::operator==(const MYMatrix& other) const noexcept {
  return this->EqMatrix(other);
}

MYMatrix MYMatrix::operator=(MYMatrix other) {
  if (matrix_ && this != &other) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
    matrix_ = nullptr;
  }
  rows_ = other.GetRows();
  cols_ = other.GetCols();
  if (this != &other) {
    matrix_ = new double*[rows_]();
    for (int i = 0; i < rows_; i++) {
      matrix_[i] = new double[cols_]();
    }
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] = other.matrix_[i][j];
      }
    }
  }
  return *this;
}

MYMatrix MYMatrix::operator+=(const MYMatrix& other) {
  SumMatrix(other);
  return *this;
}

MYMatrix MYMatrix::operator-=(const MYMatrix& other) {
  SubMatrix(other);
  return *this;
}

MYMatrix MYMatrix::operator*=(const MYMatrix& other) {
  MulMatrix(other);
  return *this;
}

MYMatrix MYMatrix::operator*=(const double number) noexcept {
  MulNumber(number);
  return *this;
}

double& MYMatrix::operator()(const int i, const int j) const {
  if (rows_ <= i || cols_ <= j) {
    throw std::logic_error("Arguments doesn't match");
  } else if (i < 0 || j < 0) {
    throw std::logic_error("Arguments doesn't match");
  }

  return matrix_[i][j];
}

// helpers

bool MYMatrix::SameSize(const MYMatrix& other) noexcept {
  return rows_ == other.rows_ && cols_ == other.cols_;
}

MYMatrix MYMatrix::CreateMinor(int row, int col) const {
  MYMatrix minor(rows_ - 1, cols_ - 1);
  for (int i = 0, minor_row = 0; i < rows_; i++) {
    for (int j = 0, minor_col = 0; j < cols_ && i != row; j++) {
      if (j != col) {
        minor.matrix_[minor_row][minor_col] = matrix_[i][j];
        minor_col++;
      }
    }
    if (i != row) minor_row++;
  }
  return minor;
}

void MYMatrix::InsertArray(double* dum) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = dum[i * cols_ + j];
    }
  }
}

void MYMatrix::SetElem(int i, int j, double elem) { matrix_[i][j] = elem; }

MYMatrix operator*(const double number, const MYMatrix& other) noexcept {
  MYMatrix buff(other);
  buff.MulNumber(number);
  return buff;
}