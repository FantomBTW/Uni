#include <cstdio>
#include <iostream>

class Point{

private:
  double x; double y;

public:
  Point(){x=0;y=0;}

  Point(double strtx, double strty){y=strty;x=strtx;}

  Point(const Point& newclass){x = newclass.x; y = newclass.y;}

  void print(){printf("(%.2lf,%.2lf)\n", x, y);}

  ~Point() {std::cout << "Point deleted" << std::endl;}
};

