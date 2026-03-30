#include <iostream>

using namespace std;

class Counter{
  private:
    int value;
  public:
    Counter(){
      value = 0;
    }

    Counter(int start){
      value = start;
    }

    void increment(){
      value++;
    }

    int getValue(){
      return value;
    }

    ~Counter() {
      cout << "уничтожение" << endl;
    }
};

int main(){
  Counter countDef;//Default
  Counter countSpec(5);//Specific

  for (int i = 0; i < 3; i++){
    countDef.increment(); countSpec.increment();
  }

  cout << countDef.getValue() << endl << countSpec.getValue() << endl;
  return 0;
}
