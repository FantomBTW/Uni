#include <iostream>
using namespace std;
#define CNT 3

double calcAverage(const int grades[], int size);

struct Student{
  string name;
  string group;
  int grades[5];
};

int main(){
  Student IVB[3];
  for (int i=0; i<CNT; i++){
    cout << "enter student name group and grades for 5 exms";
    cin >> IVB[i].name >> IVB[i].group;
    for (int q=0; q<5; q++)cin >> IVB[i].grades[q];
  }

  cout << endl;

  for (int i=0; i<CNT; i++){
    cout << "Student:" << IVB[i].name;
    cout << "\ngroup:" << IVB[i].group;
    cout << "\naverage grade:" << calcAverage(IVB[i].grades, 5);
    cout << endl << endl;
  }


/*
  for (int i=0; i<3; i++){
    cout << IVB[i].name << IVB[i].group;
    for (int q=0; q<5; q++)cout << IVB[i].grades[q];
  }
*/
}


double calcAverage(const int grades[], int size){
  double ave = 0;
  for (int q = 0; q<size; q++){
    if (grades[q] > 5 || grades[q] < 2)exit(1);
    ave+=(double)grades[q];
  }
  ave /= size;
  return ave;
}
