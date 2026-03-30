#include <iostream>
#include <iomanip>
using namespace std;

struct Date {
  int day;
  int month;
  int year;
};

int validateDate(Date date){
  if (date.month < 1 || date.month > 12
                  || date.day < 1
                  || date.year < 1)return 1;
  
  int dayofmonths[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
  //             0 01 02 03 04 05 06 07 08 09 10 11 12
  if (date.year%4 == 0 && date.year%100 != 0 || date.year%400 == 0)dayofmonths[2]=29;
  if (date.day > dayofmonths[date.month]) return 1;

  return 0;
}

int main() {
  Date dat;

  cout << "pls, enter the day\n";
  cin >> dat.day;
  
  cout << "pls, enter the month\n";
  cin >> dat.month;
  
  cout << "pls, enter the year\n";
  cin >> dat.year;

  if (validateDate(dat) == 1){
    cerr << "u cant date at this date" << endl;
    return 1;
  }

  cout << setfill('0') << setw(2) << dat.day;
  cout << "-";
  cout << setfill('0') << setw(2) << dat.month;
  cout << "-";
  cout << dat.year << endl;
}
