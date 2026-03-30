#include "Point.h"
using namespace std;

int main(){
  Point p1(3.0, 4.0);
  Point p2 = p1;

  p1.print();
  p2.print();

  return 0;
}
