#ifndef INCLUDE_MATRIX_VECTOR_MATRIX_HXX_
#define INCLUDE_MATRIX_VECTOR_MATRIX_HXX_

#include <ostream>
#include <string>
#include <vector>

#include "matrix/base_matrix.hxx"

using std::ostream;
using std::string;
using std::vector;

/**
 * Matrix implementation using a vector of vector as data
 */
template <class T>
class VectorMatrix : public BaseMatrix<T> {
  template <typename U>  // NOTE: Without this we get linker problems
  friend bool operator==(const VectorMatrix<U>&, const VectorMatrix<U>&);

 public:
  // https://stackoverflow.com/questions/6592512/templates-parent-class-member-variables-not-visible-in-inherited-class
  using BaseMatrix<T>::cols;
  using BaseMatrix<T>::rows;
  /**
   * Default constructor
   */
  VectorMatrix() {}

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
  // void Write(const string& file_path) const override;

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

/**
 * Equality operator
 *
 * \param lhs The left hand side operand
 * \param rhs The right hand side operand
 */
template <class T>
bool operator==(const VectorMatrix<T>& lhs, const VectorMatrix<T>& rhs);

#endif  // INCLUDE_MATRIX_VECTOR_MATRIX_HXX_
