#pragma once
#include "depart.hpp"
#include <vector>
#include <iostream>

template <typename F, typename D, typename W>
class firm{
private:
   std::vector<department<D, W>> departments;
   F firmId;
public:
   firm() : departments() {};
   firm(std::vector<department<D, W>> depsUnderFirm, F name) : departments(depsUnderFirm), firmId(name) {};

   firm(const firm& newFirm){
      departments = newFirm.departments;
      firmId = newFirm.firmId;
   }

   ~firm(){
      //std::cout << "firm doesn't exist for now" << std::endl;
   }

   void addDep(department<D, W> newDep){
      departments.push_back(newDep);
      std::cout << firmId << "had bought" << newDep.getDepId() << std::endl;
   }

   void prnDeps(){
      for (auto& dep : departments){
         dep.prnDepID();
      }
   }

   std::vector<department<D, W>> getDeps(){
      return departments;
   }

   F getFirmId(){
      return firmId;
   };
};
