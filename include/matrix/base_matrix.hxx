#ifndef INCLUDE_MATRIX_BASE_MATRIX_HXX_
#define INCLUDE_MATRIX_BASE_MATRIX_HXX_

#include <cstddef>
#include <ostream>
#include <string>

using std::ostream;
using std::size_t;
using std::string;

/**
 * Abstract Base Class contiaining the matrix
 */
template <class T>
class BaseMatrix {
 public:
  /**
   * Default constructor
   */
  BaseMatrix() {}

  /**
   * Read the matrix from a file
   *
   * \param file_path The path to the file
   */
  virtual void Read(const string& file_path) = 0;

  /**
   * Print the matrix
   *
   * \param os The ostream to print to
   * \return The modified stream
   */
  virtual ostream& Print(ostream& os) const = 0;

  /**
   * Write the matrix to a file
   *
   * \param file_path The path to the file
   */
  // virtual void Write(const string& file_path) const;

 protected:
  size_t rows; /**< Number of rows in the matrix */
  size_t cols; /**< Number of columns in the matrix */
};

#endif  // INCLUDE_MATRIX_BASE_MATRIX_HXX_
