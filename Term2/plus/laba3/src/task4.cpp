#include "Point.h"
#include <cstdlib>
using namespace std;

int main(){
  srand(time(NULL));

  Point massPoints[] = {
    Point((double)(rand()%1000)/10, (double)(rand()%1000)/10),
    Point((double)(rand()%1000)/10, (double)(rand()%1000)/10),
    Point((double)(rand()%1000)/10, (double)(rand()%1000)/10)
  };

  for (int i = 0; i < 3; i++){
    massPoints[i].print();
  }

  return 0;
}
