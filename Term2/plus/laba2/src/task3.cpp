#include <iostream>
#include <cmath>
using namespace std;

struct Point{
  double x;
  double y;
};

double distance(const Point& p1, const Point& p2);

int main(){
  Point dots[2];

  cout << "pls enter x y" << endl;
  cin >> dots[0].x >> dots[0].y;

  cout << "pls enter x y for 2nd Point" << endl;
  cin >> dots[1].x >> dots[1].y;

  cout << distance(dots[0], dots[1]);
  return 0;
}


double distance(const Point& p1, const Point& p2){
  return sqrt(pow(p2.x-p1.x, 2) + pow(p2.y-p1.y, 2));
}
