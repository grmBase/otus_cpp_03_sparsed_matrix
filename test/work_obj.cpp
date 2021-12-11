//------------------------------
#include <string>
#include <iostream>
//#include <cassert> //asssert
#include <gtest/gtest.h>
//------------------------------
#include "../include/sparse_matrix.h"
//------------------------------


TEST(CheckSomeRequirments, SomeInfo)
{
  std::cout << "in start of test func" << std::endl;

  t_matrix<int, -1> matrix;
  EXPECT_EQ(matrix.size(), 0) << "size of matrix suppose to be 0";

  auto a = matrix[0][0];
  EXPECT_EQ(a, -1) << "default value should be -1";
  //assert(matrix.size() == 0);
  EXPECT_EQ(matrix.size(), 0) << "size of marix should be 0";

  matrix[100][100] = 314;
  //assert(matrix[100][100] == 314);
  EXPECT_EQ(matrix[100][100], 314) << "elem has value 314";


  //assert(matrix.size() == 1);
  EXPECT_EQ(matrix.size(), 1) << "new size of matrix is 1";

  std::cout << "before exit of test func" << std::endl;

}
//------------------------------

