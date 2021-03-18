#include <iostream>
#include <string>

#include "matrix/vector_matrix.hxx"
using std::cout;
using std::string;

int main() {
  // NOTE: The file is relative to the binary
  // NOTE: We are copying the data directory to the build directory
  string file_name{"data/1.txt"};

  VectorMatrix<int> vm(file_name);
  // VectorMatrix vm(file_name);
  vm.Print(cout);

  return 0;
}
