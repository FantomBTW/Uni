#pragma once
#include <vector>
#include "worker.hpp"

template <typename T>
class company{
private:
   std::vector<worker<T>> department;
public:
   company() : department() {}

   company(std::vector<worker<T>> workers) : department(workers) {};

   company(const company& newCom) {
      department = newCom.department;
   }; 

   ~company(){
      std::cout << "the company was disbanded" << std::endl;
   }

   void addWorker(worker<T> newOne){
      department.push_back(newOne);
      std::cout << "HH find new one" << std::endl;
   }

   void prnWorkers(){
      for (const auto& q : company<T>::department){
         q.prnId();
      }
   }
};
