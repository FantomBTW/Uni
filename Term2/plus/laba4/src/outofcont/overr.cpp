#include <iostream>
#include <ostream>

class cls {
public:
   virtual void prntip(){
      std::cout << "idk, what is that" << std::endl;
   }
};

class newcls : public cls {
public:
   void prntip() override{
      std::cout << "new gen idk" << std::endl;
   }
};

int main(){
   std::cout << "cls" << std::endl;
   cls myCls;
   myCls.prntip();

   std::cout << "newcls" << std::endl;
   newcls mynewCls;
   mynewCls.prntip();
}
