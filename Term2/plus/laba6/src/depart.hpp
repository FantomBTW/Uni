#pragma once
#include <vector>
#include "worker.hpp"

template <typename D, typename W>
class department{
private:
   std::vector<worker<W>> depart;
   D depId;
public:
   department() : depart() {}

   department(std::vector<worker<W>> workers, D name) : depart(workers), depId(name) {};

   department(const department& newDep) {
      depart = newDep.depart;
      depId = newDep.depId;
   }; 

   ~department(){
      //std::cout << "the department was disbanded" << std::endl;
   }

   void addWorker(worker<W> newOne){
      depart.push_back(newOne);
      std::cout << "HH find new one " << newOne.getId() << " for " << depId << std::endl;
   }

   void prnWorkers(){
      for (const auto& q : department<W, D>::depart){
         q.prnId();
      }
   }

   void prnDepID(){
      std::cout << "depID is:" << depId << std::endl;
   };

   std::vector<worker<W>> getworkers(){
      return depart;
   }

   D getDepId(){
      return depId;
   };

   void change(D input){
      depId = input;
   };
};
