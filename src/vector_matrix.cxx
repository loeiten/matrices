#include "matrix/vector_matrix.hxx"

#include <algorithm>
#include <exception>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using std::count;
using std::endl;
using std::getline;
using std::ifstream;
using std::istreambuf_iterator;
using std::istringstream;
using std::ostringstream;
using std::runtime_error;
using std::string;
using std::stringstream;
using std::vector;

template <class T>
VectorMatrix<T>::VectorMatrix(const string& file_path) {
  this->Read(file_path);
}

template <class T>
void VectorMatrix<T>::FillData(ifstream& in_file) {
  string line;

  vector<T> row;
  while (getline(in_file, line)) {
    istringstream line_stream(line);
    T number;
    while (line_stream >> number) {
      row.push_back(number);
    }
    data.push_back(row);
    // Remember to remove the contents of the row
    row.clear();
  }
}

template <class T>
ostream& VectorMatrix<T>::Print(ostream& os) const {
  string out_string;
  ostringstream out_stream;

  for (const auto& cur_row : data) {
    for (const auto& cur_el : cur_row) {
      out_stream << cur_el << " ";
    }
    // Remove the last space
    out_string = out_stream.str();
    // Reset the out_stream
    out_stream.clear();
    out_stream.seekp(0);
    os << out_string.substr(0, out_string.size() - 1) + "\n";
  }
  return os;
}

template <class T>
bool operator==(const VectorMatrix<T>& lhs, const VectorMatrix<T>& rhs) {
  // FIXME: YOU ARE HERE: CHECK THAT THE DIMENSIONS FIT BEFORE CHECKING ELEMENTS

  return true;
}

// NOTE: Must declare the templates a place where the compiler can find them
//       https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file
template class VectorMatrix<int>;
template class VectorMatrix<double>;
