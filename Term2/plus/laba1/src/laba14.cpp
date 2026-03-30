#include <iostream>


int main()
{
  int str=0;int stlb=0;

  std::cout << "введите желаемый размер матрицы in str:";
  std::cin >> str;

  std::cout << std::endl;
  
  std::cout << "введите желаемый размер матрицы in stlb:";
  std::cin >> stlb;

  if (str <= 0 || stlb <= 0 ){
    std::cerr << "невозможный размер матрицы";
    return 1;
  }

  std::cout << "create matrix" << std::endl;
  int** matrix = new int*[str];
  std::cout << "matrix created" << std::endl;

  for (int q =0; q < str; q++)
  {
    matrix[q] = new int[stlb];
  }

  for (int strok = 0; strok < str; strok++)
  {
    for (int stolb = 0; stolb < stlb; stolb++)
    {
      matrix[strok][stolb] = 0;
    }
  }

  for (int strok = 0; strok < str; strok++)
  {
    for (int stolb = 0; stolb < stlb; stolb++)
    {
      std::cout << matrix[strok][stolb] << " ";
    }
    std::cout << std::endl;
  }

  for (int q =0; q < str; q++)
  {
    delete[] matrix[q];
  }
  delete[] matrix;
}
