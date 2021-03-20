#ifndef INCLUDE_MATRIX_VECTOR_MATRIX_HXX_
#define INCLUDE_MATRIX_VECTOR_MATRIX_HXX_

#include <fstream>
#include <ostream>
#include <string>
#include <vector>

#include "matrix/base_matrix.hxx"

using std::ifstream;
using std::ostream;
using std::string;
using std::vector;

/**
 * Matrix implementation using a vector of vector as data
 */
template <class T>
class VectorMatrix : public BaseMatrix<T> {
  template <class U>  // NOTE: Without this we get linker problems
  friend bool operator==(const VectorMatrix<U>&, const VectorMatrix<U>&);
  template <class U>
  friend bool operator!=(const VectorMatrix<U>&, const VectorMatrix<U>&);
  template <class U>
  friend ostream& operator<<(ostream&, const VectorMatrix<U>&);

 public:
  // https://stackoverflow.com/questions/6592512/templates-parent-class-member-variables-not-visible-in-inherited-class
  using BaseMatrix<T>::cols;
  using BaseMatrix<T>::rows;
  /**
   * Default constructor
   */
  VectorMatrix() = default;

  /**
   * Construct from a vector
   *
   * \param d The data to be copied to the matrix' internal data
   */
  explicit VectorMatrix(vector<vector<T>> d) : data(d) {
    rows = d.size();
    cols = d[0].size();
  }

  /**
   * Construct from file
   *
   * \param file_path The path to the file
   */
  explicit VectorMatrix(const string& file_path);

  /**
   * Print the matrix
   *
   * \param os The ostream to print to
   * \return The modified stream
   */
  ostream& Print(ostream& os) const override;

  /**
   * Write the matrix to a file
   *
   * \param file_path The path to the file
   */
  void Write(const string& file_path) const override;

  /**
   * Return copy of the underlying data
   *
   * \return A copy of the underlying data
   */
  vector<vector<T>> GetDataCopy() const;

 private:
  vector<vector<T>> data; /**< The data containing the matrix */
  /**
   * Fill the data
   *
   * NOTE: This function will not close the file stream
   *
   * \param in_file The filestream used to filling the matrx
   */
  void FillData(ifstream& in_file) override;
};

// NOTE: We define friend functions here
//       There probably is a way to define them in the .cxx file, see
//       https://stackoverflow.com/questions/4660123/overloading-friend-operator-for-template-class
//       https://stackoverflow.com/questions/4285826/defining-friend-function-within-templated-class

/**
 * Equality operator
 *
 * \param lhs The left hand side operand
 * \param rhs The right hand side operand
 */
template <class T>
bool operator==(const VectorMatrix<T>& lhs, const VectorMatrix<T>& rhs) {
  // Dimention mismatch
  if ((lhs.cols != rhs.cols) || (lhs.rows != rhs.rows)) {
    return false;
  }

  for (size_t i = 0; i < lhs.rows; i++) {
    for (size_t j = 0; j < lhs.cols; j++) {
      if (lhs.data[i][j] != rhs.data[i][j]) {
        return false;
      }
    }
  }
  return true;
}

/**
 * Inequality operator
 *
 * \param lhs The left hand side operand
 * \param rhs The right hand side operand
 */
template <class T>
bool operator!=(const VectorMatrix<T>& lhs, const VectorMatrix<T>& rhs) {
  return !(lhs == rhs);
}

/**
 * Bitwise shift left operator
 *
 * \param os The output stream
 * \param rhs The right hand side operand
 */
template <class T>
ostream& operator<<(ostream& os, const VectorMatrix<T>& rhs) {
  return rhs.Print(os);
}

#endif  // INCLUDE_MATRIX_VECTOR_MATRIX_HXX_
