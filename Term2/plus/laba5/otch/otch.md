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

### по лабораторной работе № 5

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
Сделать классы для отслеживания текущих работников и их найма
main.cpp
```cpp
#include "worker.hpp"
#include "firm.hpp"
#include <string>

int main(){
   company<std::string> Linux_Foundation;
   Linux_Foundation.addWorker(worker<std::string>("Linus"));
   Linux_Foundation.addWorker(worker<std::string>("Richard"));

   Linux_Foundation.prnWorkers();
}
```

worker.hpp
```hpp
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
```

firm.hpp
```hpp
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
```

Вывод:я узнал способы и особенности работы с шаблонами в c++.
