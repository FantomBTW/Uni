#pragma once
#include <iostream>

template <typename W>
class worker{
private:
   W Id;
public:
   worker() : Id(W{}) {}

   worker(const W& input) : Id(input) {}

   worker(const worker<W>& newcl){
      Id = newcl.Id;
   }

   ~worker(){
      //std::cout << "увольнение: " << Id << std::endl;
   };

   W getId(){
      return Id;
   };

   void prnId() const{
      std::cout << Id << std::endl;
   };

   void change(W input){
      Id = input;
   };
};
