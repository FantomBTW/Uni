#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <new>

using namespace std;

struct Book{
  string title;
  string author;
  int year;
};


void printBook(const Book* book);


int main(){
  const int N = 4;
  Book* library = new(nothrow) Book[N];

  if (library == nullptr){
    cerr << "ошибка выделения памяти" << endl;
    return 1;
  }

  for (int i=0; i < N; i++){
    std::cout << "Enter book name Num" << i+1 << endl;
    cin.ignore(i == 0 ? 0 : 1, '\n');
    getline(cin, (library + i) -> title);
    cout << "Enter book author" << endl;
    getline(cin, (library + i) -> author);
    cout << "Enter the year" << endl;
    cin >> (library + i) -> year;
    cout << endl;
  }

  cout << setw(3) << "N" << setw(17) << "title" << setw(20) << "author" << setw(6) << "year" << endl;
  for (int i=0; i < N; i++){
    cout << setw(3) << i+1 << setw(17) << (library + i) -> title << setw(20) << (library + i) -> author << setw(6) << (library + i) -> year << endl;
  }

  cout << endl;
  srand(time(NULL));
  int bookOfDay = rand()%N;
  printBook((library+bookOfDay));

  delete[] library;

  return 0;
}

/*
  а теперь, как я это ваще понял, мы обращаемcя к полю указателя
  тобишь по адресу "Русановская" к полю, свойственному каждому схоже адресу(это уже базово для структур)
*/ 

void printBook(const Book* book){
  cout << "book of the day:\n" << book -> title
    << "\nthat released at:\n" << book -> year << "\nby:\n" << book ->author;
  return;
}
