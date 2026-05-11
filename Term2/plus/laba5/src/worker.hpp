#pragma once
#include <iostream>

template <typename T>
class worker{
private:
   T Id;
public:
   worker() : Id(T{}) {}

   worker(const T& input) : Id(input) {}

   worker(const worker<T>& newcl){
      Id = newcl.Id;
   }

   ~worker(){
      std::cout << "увольнение: " << Id << std::endl;
   };

   T getId(){
      return Id;
   };

   void prnId() const{
      std::cout << Id << std::endl;
   };

   void change(T input){
      Id = input;
   };
};
