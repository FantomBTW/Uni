#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main()
{
  int size;
  cout << "введите желаемый размер массива:"; cin >> size;
   
  if (size <= 0)
  {
    cerr << "невозможный размер массива";
    return 1;
  }
  
  int *p =new(nothrow) int[size];

  if (p==nullptr)
  {
    cerr << "слишком большой массив";
    return 2;
  }

  srand(time(NULL));
  for (int q=0; q < size; q++)
  {
    p[q] = rand()%100;
  }

  for (int i=0; i < size; i++)
  {
    cout << p[i] << " ";
  }

  delete[] p;
  
  return 0;
  
}
