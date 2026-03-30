#include "Point.h"
#include <cstdlib>
#include <memory>
using namespace std;

int main(){
  srand(time(NULL));

  Point* newobj = new Point(3.2, 2.3);
  newobj -> print();
  delete newobj;
  cout << "newobj must be deleted here" << endl; // ну тут ок, создаём указатель, вспоминаем третью или какую там задачу
  
  Point p((double)(rand()%1000)/10, (double)(rand()%1000)/10);
  Point& ref = p;
  ref.print();

  

  unique_ptr<Point> smartassPoint = make_unique<Point>(
    (double)(rand()%1000)/10, (double)(rand()%1000)/10
  );
  smartassPoint->print();
  return 0;
}
