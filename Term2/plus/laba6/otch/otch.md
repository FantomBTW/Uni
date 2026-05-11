<div align="center">

МИНИСТЕРСТВО ТРАНСПОРТА РОССИЙСКОЙ ФЕДЕРАЦИИ  
ФЕДЕРАЛЬНОЕ АГЕНТСТВО ЖЕЛЕЗНОДОРОЖНОГО ТРАНСПОРТА  
Государственное бюджетное образовательное учреждение  
высшего образования  
**«ПЕТЕРБУРГСКИЙ ГОСУДАРСТВЕННЫЙ УНИВЕРСИТЕТ  
ПУТЕЙ СООБЩЕНИЯ ИМПЕРАТОРА АЛЕКСАНДРА I»**  

Кафедра «ИНФОРМАЦИОННЫЕ И ВЫЧИСЛИТЕЛЬНЫЕ СИСТЕМЫ»  

---

Дисциплина: «Программирование C++»

<br><br><br>
<br><br><br>

### О Т Ч Е Т

### по лабораторной работе № 6

</div>

<br><br><br>
<br><br><br>

<div align="right">
  <table align="right" style="border: none;">
    <tr>
      <td style="text-align: left; border: none;">
        Выполнил студент<br>
        Факультета АИТ<br>
        Группы ИВБ-515<br>
        Принял
      </td>
      <td style="text-align: right; border: none; vertical-align: bottom; padding-left: 50px;">
        Нартов С. А.<br>
        <br>
        <br>
        Хетчиков Д.М.
      </td>
    </tr>
  </table>
</div>

<br><br><br>
<br><br><br>
<br><br><br>
<br><br><br><br><br>

<div align="center">
  Санкт-Петербург<br>  
  2026<br>
</div>

# Задание
расширить программу из лабораторной работы 5 для показа возможностей Композиции
main.cpp
```cpp
#include "depart.hpp"
#include "firm.hpp"
#include "worker.hpp"
#include <iostream>
#include <string>
#include <vector>

#define F std::string
#define D std::string
#define W std::string

department<D, W> createGULAG(){
   worker<W> w1("worker 1");
   worker<W> w2("worker 2");
   worker<W> w3("worker 2");

   std::vector<worker<W>> joblesses;
   joblesses.push_back(w1);
   joblesses.push_back(w2);
   joblesses.push_back(w3);

   D mahname = "mah";

   department<D, W> mah(joblesses, mahname);
   return mah;
}

department<D, W> makeWorse(){
   std::vector<worker<W>> joblesses;

   worker<W> w100("worker 100");
   worker<W> w200("worker 200");

   joblesses.push_back(w100);
   joblesses.push_back(w200);

   D VKmsgName = "evilmessanger";

   department<D, W> VKmsg(joblesses, VKmsgName);
   return VKmsg;
};


int main(){
   F evilCorpName = "VK";
   department<D, W> mah = createGULAG();

   department<D, W> VKmsg = makeWorse();

   firm<F, D, W> evilCorp(std::vector<department<D, W>>{mah, VKmsg}, evilCorpName);

   std::cout << std::endl;

   std::cout << evilCorp.getFirmId() << std::endl;
   for (auto& i : evilCorp.getDeps()){
      std::cout << '\t' << i.getDepId() << std::endl;
      for (auto& j : i.getworkers()){
         std::cout << '\t' << '\t' << j.getId() << std::endl;
      }
   }

   std::cout << std::endl;
}
```

firm.cpp
```cpp
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
```

depart.hpp
```cpp
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
```

worker.hpp
```cpp
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
```

CMakeLists.txt
```CMakeLists.txt
cmake_minimum_required(VERSION 3.11)

project(comp)

add_executable(
   comp
   main.cpp
)
```

Вывод: Я узнал о композиции, случайно использованной в течении прошлой лабораторной работы.
