#include <iostream>
using namespace std;

int main()
{
  //выделяем память
  int *p = new(nothrow) int;

  //проверка
  if (p==nullptr)
  {
    cerr << "error with memory";
    return 1;
  }

  //запрашиваем число
  cout << "Введите число для хранения\n"; cin >> *p;
  
  //выводим
  cout << "ваше число --- " << *p << endl;
  //очищаем
  delete p;
  
  return 0;
}
