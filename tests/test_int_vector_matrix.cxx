#include <boost/test/unit_test.hpp>
#include <string>
#include <vector>

#include "matrix/vector_matrix.hxx"

using std::string;
using std::vector;

struct SmallMatrix {
  SmallMatrix() : vm1(VectorMatrix<int>("data/1.txt")) {}

  VectorMatrix<int> vm1;
};

BOOST_AUTO_TEST_SUITE(IntVectorMatrix)

BOOST_FIXTURE_TEST_CASE(small_matrix_equal, SmallMatrix) {
  VectorMatrix<int> vm2 = vm1;
  BOOST_TEST(vm1 == vm2);
}

BOOST_FIXTURE_TEST_CASE(small_matrix_vector_constructor, SmallMatrix) {
  VectorMatrix<int> vm2(
      vector<vector<int>>{vector<int>{1, 2}, vector<int>{3, 4}});
  BOOST_TEST(vm1 == vm2);
}

BOOST_FIXTURE_TEST_CASE(small_matrix_diff_01, SmallMatrix) {
  VectorMatrix<int> vm2(
      vector<vector<int>>{vector<int>{1, 20}, vector<int>{3, 4}});
  BOOST_TEST(vm1 != vm2);
}

BOOST_FIXTURE_TEST_CASE(small_matrix_diff_10, SmallMatrix) {
  VectorMatrix<int> vm2(
      vector<vector<int>>{vector<int>{1, 2}, vector<int>{30, 4}});
  BOOST_TEST(vm1 != vm2);
}

BOOST_FIXTURE_TEST_CASE(small_matrix_diff_cols, SmallMatrix) {
  VectorMatrix<int> vm2(
      vector<vector<int>>{vector<int>{1, 2, 3}, vector<int>{4, 5, 6}});
  BOOST_TEST(vm1 != vm2);
}

BOOST_FIXTURE_TEST_CASE(small_matrix_diff_rows, SmallMatrix) {
  VectorMatrix<int> vm2(vector<vector<int>>{
      vector<int>{1, 2}, vector<int>{3, 4}, vector<int>{5, 6}});
  BOOST_TEST(vm1 != vm2);
}

BOOST_AUTO_TEST_SUITE_END()
