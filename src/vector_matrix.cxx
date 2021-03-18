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
using std::ofstream;
using std::ostringstream;
using std::runtime_error;
using std::string;
using std::stringstream;
using std::vector;

template <class T>
VectorMatrix<T>::VectorMatrix(const string& file_path) {
  Read(file_path);
}

template <class T>
void VectorMatrix<T>::Read(const string& file_path) {
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

  in_file.close();
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
