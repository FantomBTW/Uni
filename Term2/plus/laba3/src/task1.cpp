#include <iostream>

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
      std::cout << "уничтожение" << std::endl;
    }
};

int main(){
   Counter countDef;//Default
   Counter countSpec(5);//Specific

   for (int i = 0; i < 3; i++){
      countDef.increment(); countSpec.increment();
   }

   std::cout << countDef.getValue() << std::endl << countSpec.getValue() << std::endl;
   return 0;
}
