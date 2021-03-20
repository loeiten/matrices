#include <iostream>
#include <string>

#include "matrix/vector_matrix.hxx"

using std::cout;
using std::endl;
using std::string;

int main() {
  // NOTE: The file is relative to the binary
  // NOTE: We are copying the data directory to the build directory
  string file_name{"data/1.txt"};

  VectorMatrix<int> vm(file_name);
  VectorMatrix<int> vm2 = vm;

  if (vm == vm2) {
    cout << "vm == vm2" << endl;
  } else {
    cout << "vm != vm2" << endl;
  }

  cout << "Using Print(cout):" << endl;
  vm.Print(cout);

  cout << "Using cout << vm:" << endl;
  cout << vm << endl;

  return 0;
}
