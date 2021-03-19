#include "matrix/base_matrix.hxx"

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
using std::runtime_error;
using std::string;
using std::stringstream;

template <class T>
void BaseMatrix<T>::Read(const string& file_path) {
  ifstream in_file(file_path);

  if (!in_file.is_open()) {
    stringstream ss{"Could not open \""};
    ss << file_path << "\"" << endl;
    throw runtime_error(ss.str());
  }

  // Find size of matrix
  cols = 0;
  string line;
  string tmp;
  // Get the first line
  getline(in_file, line);
  stringstream iss(line);
  while (iss >> tmp) {
    ++cols;
  }

  rows = static_cast<size_t>(count(istreambuf_iterator<char>(in_file),
                                   istreambuf_iterator<char>(), '\n'));

  // Reset file to start
  in_file.clear();
  in_file.seekg(0);

  FillData(in_file);

  in_file.close();
}

// NOTE: Must declare the templates a place where the compiler can find them
//       https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file
template class BaseMatrix<int>;
template class BaseMatrix<double>;
