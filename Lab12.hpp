#pragma once

#include <vector>

template <typename T>
class Matrix {
private:
  using row_t = std::vector<T>;
  std::vector< row_t > matrix;

public:
  // Default constructor makes and empty Matrix
  Matrix() { }

  // Constructor can specify size, and (optional) default value
  Matrix(size_t rows, size_t cols, T init_val=T{})
    : matrix(rows, std::vector<T>(cols, init_val))
  { }

  // Copy constructor should copy everything directly, so default works
  Matrix(const Matrix<T> &) = default;

  // Assignment Operator
  Matrix<T>& operator=(const Matrix<T> &) = default;

  // Size acessors allow us to retrieve the Width or Height
  size_t GetWidth() const { return matrix.size() ? matrix[0].size() : 0; }
  size_t GetHeight() const { return matrix.size(); }

  // Data accessors allow us to access values at specific rows and columns
  T & GetValue(size_t row, size_t col) { return matrix[row][col]; }  
  T GetValue(size_t row, size_t col) const { return matrix[row][col]; }
  
  // WRITE THE IsSameSize MEMBER FUNCTION.
  template <typename Z>
  bool IsSameSize(const Matrix<Z> &other) const {
    return GetHeight() == other.GetHeight() && GetWidth() == other.GetWidth();}

  // ADD AN operator[] MEMBER FUNCTION
  row_t &operator[](size_t row) { return matrix[row]; }
  const row_t &operator[](size_t row) const { return matrix[row]; }


  // ADD A Write MEMBER FUNCTION
  void Write(std::ostream &os) const {
    for (const auto &row : matrix) {
      os << '{';
      for (const auto &item : row) {
        os << item << ',';
      }
      os << "},";
    }
  }


  // ADD AN operator+ MEMBER FUNCTION
  Matrix<T> operator+(const Matrix<T> &other) const {
    if (!IsSameSize(other)) {
      return Matrix<T>();
    }
    Matrix<T> result(GetHeight(), GetWidth());
    for (size_t row = 0; row < GetHeight(); ++row) {
      for (size_t col = 0; col < GetWidth(); ++col) {
        result[row][col] = GetValue(row, col) + other.GetValue(row, col);
      }
    }
    return result;
  }


  // ADD AN operator* MEMBER FUNCTION
  Matrix<T> operator*(const T &scalar) const {
    Matrix<T> result(GetHeight(), GetWidth())n;
    for (size_t row = 0; row < GetHeight(); ++row) {
      for (size_t col = 0; col < GetWidth(); ++col) {
        result[row][col] = GetValue(row, col) * scalar;
      }
    }
    return result;
  }
};

// ADD AN operator<< REGULAR (NOT MEMBER) FUNCTION
template <typename T>
std::ostream &operator<<(std::ostream &os, const Matrix<T> &matrix) {
  matrix.Write(os);
  return os;
}

