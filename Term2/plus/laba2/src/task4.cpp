#include <iostream>
#include <iomanip>

using namespace std;

struct Book{
  string title;
  string author;
  int year;
};


int findOldInd(const Book libr[], int N);


int main(){
  const int N = 4;
  Book libr[N];

  for (int i=1; i <= N; i++){
    std::cout << "Enter book name Num" << i << endl;
    cin.ignore(i == 1 ? 0 : 1, '\n');
    getline(cin, libr[i-1].title);
    cout << "Enter book author" << endl;
    getline(cin, libr[i-1].author);
    cout << "Enter the year" << endl;
    cin >> libr[i-1].year;
    cout << endl;
  }

  cout << setw(3) << "N" << setw(17) << "title" << setw(20) << "author" << setw(6) << "year" << endl;
  for (int i=0; i < N; i++){
    cout << setw(3) << i+1 << setw(17) << libr[i].title << setw(20) << libr[i].author << setw(6) << libr[i].year << endl;
  }

  int indexOfOld = findOldInd(libr, N);
  cout << "the oldest book is:" << libr[indexOfOld].title << '\n';
  cout << "by:" << libr[indexOfOld].author << '\n';
  cout << "released at:" << libr[indexOfOld].year << endl;
  return 0;
}

int findOldInd(const Book libr[], int N){
  int minYearInd = 0;
  for (int i = 1; i < N; i++) {
    if (libr[i].year < libr[minYearInd].year) {
      minYearInd = i;
    }
  }
  return minYearInd;
}

