#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main()
{
  int size;
  cout << "Введите желаемый размер массива:"; cin >> size;

  if (size <= 0)
  {
    cout << "невозможный размер массива";
    return 1;
  }

  int *p = (int*)malloc(10 * sizeof(int));
  if (p == nullptr)
  {
    cerr << "ошибка выделения памяти";
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
  
  free(p);
}
