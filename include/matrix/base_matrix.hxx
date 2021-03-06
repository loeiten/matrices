#ifndef INCLUDE_MATRIX_BASE_MATRIX_HXX_
#define INCLUDE_MATRIX_BASE_MATRIX_HXX_

#include <cstddef>
#include <fstream>
#include <ostream>
#include <string>

using std::ifstream;
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
  BaseMatrix() = default;

  /**
   * Read the matrix from a file
   *
   * \param file_path The path to the file
   */
  void Read(const string& file_path);

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
  virtual void Write(const string& file_path) const = 0;

 protected:
  size_t rows; /**< Number of rows in the matrix */
  size_t cols; /**< Number of columns in the matrix */

 private:
  /**
   * Fill the data
   *
   * NOTE: This function will not close the file stream
   *
   * \param in_file The filestream used to filling the matrx
   */
  virtual void FillData(ifstream& in_file) = 0;
};

#endif  // INCLUDE_MATRIX_BASE_MATRIX_HXX_
