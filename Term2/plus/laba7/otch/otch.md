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

### по лабораторной работе № 7

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
изучить различные списки/листы в c++;

```cpp
#include "fn/task1.hpp"
#include "fn/task2.hpp"
#include "fn/task3.hpp"
#include "fn/task4.hpp"

int main(){
    task1();
    task2();
    task3();
    task4();
}
```

worker.hpp
```hpp
```

cls.hpp
```hpp
#pragma once
template <typename T>
class worker {
private:
    T id;
    int prod; // productivity
public:
    worker(T id, int prod): id(id), prod(prod) {};

    T getId(){
        return id;
    }

    int getprod(){
        return prod;
    }

    bool operator<(const worker& anotherworker) const{
        return prod < anotherworker.prod;
    }

    int operator+(const worker& anotherworker) const{
        return prod+anotherworker.prod;
    }

    bool operator==(const worker& anotherworker) const{
        return id == anotherworker.id;
    }

    bool operator==(const T& anotherworker) const{
        return id == anotherworker;
    }
};
```

fn/task1
```cpp
```
#include <algorithm>
#include <iostream>
#include <vector>
#include "../cls/wrk.hpp"

void task1(){
    std::vector<worker<std::string>> department;

    department.push_back(worker<std::string> ("vasya", 5));
    department.push_back(worker<std::string> ("vika", 10));
    department.push_back(worker<std::string> ("voldemar", 1));

    std::sort(department.begin(), department.end());

    std::cout << "worker of the month?" << std::endl;
    std::reverse(department.begin(), department.end());
    for (auto x : department){
        std::cout << x.getId() << " has productivity lvl:"<< x.getprod() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "what is vika productivity?" << std::endl;
    
    auto i = std::find(department.begin(), department.end(), std::string("vika"));
    std::cout << "she has productivity lvl:" << i->getprod() << std::endl;
}

fn/task2
```cpp
#include <algorithm>
#include <iostream>
#include <list>
#include <string>

void task2(){
    std::list<std::string> tasklist;

    tasklist.push_back("write backend");
    tasklist.push_front("write frontend");
    tasklist.push_front("deploy");
    tasklist.push_front("deploy");

    tasklist.sort();
    tasklist.unique();

    for (auto x : tasklist){
        std::cout << x << '\n';
    }
}
```

fn/task3
```cpp
#include <iostream>
#include <set>
#include <string>

void task3(){
    std::set<std::string> setlist;

    setlist.insert("vika");
    setlist.insert("vasya");
    setlist.insert("vika");
    setlist.insert("vova");

    for (const auto& name : setlist){
        std::cout << name << '\n';
    }
    std::cout << std::endl;

    std::cout << "vova found status: " << (setlist.find("vova") == setlist.end());

    std::cout << "vova found status: " << (setlist.find("vlad") == setlist.end());
}
```

fn/task4
```cpp
#include <iostream>
#include <stack>
#include <string>

void task4(){
    std::stack<std::string> podpisOfJournal; // обычно последним подписывают журнал тому, кто первый подошёл

    podpisOfJournal.push("Vanya 517");
    podpisOfJournal.push("Serzhiq 515");
    podpisOfJournal.push("Vanya 511");

    while (!podpisOfJournal.empty()){
        std::cout << "journal has podpised for: " << podpisOfJournal.top();
        podpisOfJournal.pop();
        std::cout << std::endl;
    }
}
```

CMakeLists.txt
```CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(exe)

add_executable(
    exe 
    main.cpp
)
```

Вывод:я узнал способы работы с различными шаблонами в c++;
