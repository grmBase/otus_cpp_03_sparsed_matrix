//------------------------------
#include <string>
#include <iostream>
#include <cassert> //asssert
//------------------------------
#include "work_obj.h"
//------------------------------
#include "include/sparse_matrix.h"
//------------------------------



int t_work_obj::func1()
{

  std::cout << "start func#1" << std::endl;

  t_matrix<int, -1> matrix;

  assert(matrix.size() == 0);

  auto a = matrix[0][0];

  assert(a == -1);
  assert(matrix.size() == 0);

  matrix[100][100] = 314;
  assert(matrix[100][100] == 314);
  assert(matrix.size() == 1);




  auto iter1 = matrix.begin();
  auto iter2 = matrix.end();

  if (iter1 != iter2) {
    std::cout << "Not equal" << std::endl;
  }




  // Тут по идее лучше ссылку, но так было в задании, поэтому оставил
  for(auto c : matrix)
  {
    int x = 0, y = 0, v = 0;

    std::tie(x, y, v) = c;

    // оставил, как было в задании:
    std::cout << x << y << v << std::endl;

    //std::cout << "x: " << x << ", y: " << y << ", value: " << v << std::endl;
  }


  std::cout << "func#1 finished" << std::endl;
  return 0;
}
//------------------------------


int t_work_obj::func2()
{

  std::cout << std::endl << "start func#2" << std::endl;

  t_matrix<int, 0> matrix;


  size_t un_max1 = 10;
  for(size_t i = 0; i < un_max1; ++i)
  {
    matrix[i][i] = i;
    matrix[un_max1 - 1 - i][i] = (un_max1 - 1 - i);
  }

  std::cout << "filling comleted" << std::endl;

  
  std::cout << std::endl << "submatrix [1, 1] to [8, 8]:" << std::endl;

  size_t un_max2 = 9;
  for (size_t i = 1; i < un_max2; ++i) {
    for (size_t j = 1; j < un_max2; ++j) {
      std::cout << matrix[i][j] << ' ';
    }

    std::cout << std::endl;
  }


  std::cout << std::endl << "total occupied cells: " << matrix.size() << std::endl;


  std::cout << "all occupied cells, coordinates, values:" << std::endl;

  // Тут уже решил сделать более оптимально, раз код мой:
  for(const auto& c : matrix)
  {
    
    int x = 0, y = 0, v=0;
    std::tie(x, y, v) = c;
    //std::cout << x << y << v << std::endl;
    std::cout << "x: " << x << ", y: " << y << ", value: " << v << std::endl;
  }


  return 0;
}
//------------------------------