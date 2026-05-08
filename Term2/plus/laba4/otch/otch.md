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

### по лабораторной работе № 4

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
Сделать классы для симуляции боевой механики днд

main
```cpp
#include <iostream>
#include <vector>
#include "raylib.h"
#include "rlgl.h"
//#include "funcs.hpp"
#include "cls/classes.hpp"
#include "settings.hpp"

int main() {
   settings par;
   InitWindow(par.width, par.height, "dnd");
   SetTargetFPS(60);

   std::cout << "init units" << std::endl;
   std::vector<unit> heros;
   std::vector<unit> monsters;

   monsters.push_back(unit(10, 6, 12, {20, 20}));
   heros.push_back(unit(15, 8, 17, {50, 50}));
   
   while (!WindowShouldClose()) {
      BeginDrawing();
      ClearBackground(RAYWHITE);

      /*
      rlPushMatrix();
         rlTranslatef(2.5f, -25, 0);
         rlRotatef(90, 1, 0, 0);
         DrawGrid(100, 5*N);
      rlPopMatrix();
      */


         for (int i = 0; i < heros.size(); i++){
            DrawCircle(
                  heros[i].getpos().x,
                  heros[i].getpos().y,
                  par.dotSize,
                  par.clrheroes
            );
         }

         for (int i = 0; i < monsters.size(); i++){
            DrawCircle(
                  monsters[i].getpos().x,
                  monsters[i].getpos().y,
                  par.dotSize,
                  par.clrmonsters
            );
         }
      EndDrawing();
   }
   CloseWindow();

   return 0;
}
```

cls/classes.cpp
```cpp
#include "classes.hpp"
#include <raylib.h>
#include <cstdlib>

void unit::attack(unit& target){
   int hitrate = rand()%20 + 1;
   int dmg = rand()%dmgDice + 1;
   target.getDmg(hitrate, dmg);
}

unit::unit(int HP, int dmg, int defend, Vector2 posVal){
   Hp = HP;
   dmgDice = dmg;
   def = defend;
   pos = posVal;
};

unit::unit(const unit& newcl){
   Hp = newcl.Hp;
   dmgDice = newcl.dmgDice;
   def = newcl.def;
};

unit::~unit(){};

void unit::getDmg(int hit, int dmg){
   if (hit >= def){
      if (dmg > Hp) {
         isAlive = 0;
         Hp = 0;
      } else {
         Hp -= dmg;
      };
   } else if (dmg < 0/*heal is -dmg*/){
      Hp -= dmg;
   }
}

void unit::move(Vector2 mv){
   pos.x += mv.x;
   pos.y += mv.y;
}

Vector2 unit::getpos(){
   return pos;
}


void cleric::heal(
      int healrate,
      int flatheal/*+ ваш модификатор базовой характеристики. */,
      unit& target
      )
{
   int healVal = rand()%healrate + 1;
   healVal = healVal * -1;/*heal is -dmg*/
   target.getDmg(0, healVal); // ckep hitrate check when (dmg <= 0)
}

void cleric::Healing_word(unit& target){
   heal(4, mainStat, target);
}

void cleric::cure_wounds(unit& target){
   heal(8, mainStat, target);
}
```

cls/classes.hpp
```hpp
#pragma once

#include <raylib.h>

class unit{
protected:
   bool isAlive = 1;
   int Hp;
   int dmgDice;
   int def;
   Vector2 pos;

   void attack(unit& target);
public:
   unit(int HP, int dmg, int defend, Vector2 posVal);;

   unit(const unit& newcl);

   ~unit();

   void getDmg(int hit, int dmg);

   void move(Vector2 mv);

   Vector2 getpos();
};

class cleric : public unit{
private:
   int mainStat = 2;
   void heal(int healrate, int flatheal, unit& target);
public:
   void Healing_word(unit& target);
   void cure_wounds(unit& target);
};
```

settings.hpp
```hpp
#pragma once
#include "raylib.h"

#define N 2

struct settings{
   int width = 1920;
   int height = 1080;
   Color clrmonsters = RED;
   Color clrheroes = BLUE;
   float dotSize = 5.0f * N;
};
```

```CMakeLists.txt
cmake_minimum_required(VERSION 3.11)
include(FetchContent)

project(dnd)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

FetchContent_Declare(
   raylib
   GIT_REPOSITORY https://github.com/raysan5/raylib.git
   GIT_TAG 5.5
)
FetchContent_MakeAvailable(raylib)

add_executable(dnd 
   main.cpp
   cls/classes.cpp
   #fn/funcs.cpp # здесь должны были быть фишки типо ИИ монстров, логика движения и куча...
)

target_link_libraries(dnd PRIVATE raylib)
target_include_directories(dnd PRIVATE ${PROJECT_SOURCE_DIR}/incls)
```

В дальнейшем будут приведены небольшие файлы показывающие, моё понимание остальных вопросов, не затронутых в "набросках" этой симуляции

