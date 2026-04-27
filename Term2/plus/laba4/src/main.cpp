#include <iostream>
#include <vector>
#include "raylib.h"
#include "funcs.hpp"
#include "classes.hpp"

struct settings{
   int width = 800;
   int height = 600;
   Color clrmonsters = RED;
   Color clrheroes = BLUE;
   float dotSize = 2.0;
};

int main() {
   settings par;
   InitWindow(par.width, par.height, "dnd");
   SetTargetFPS(60);

   std::cout << "init units";
   std::vector<unit> heros;
   std::vector<unit> monsters;
   
   monsters.push_back(unit(10, 6, 12, {0, 0}));
   heros.push_back(unit(15, 8, 17, {10, 10}));
   
   while (!WindowShouldClose()) {
      BeginDrawing();
         for (int i = 0; i <= heros.size(); i++){
            DrawCircle(heros[i].getpos().x, heros[i].getpos().y, par.dotSize, par.clrheroes);
         }

         for (int i = 0; i <= monsters.size(); i++){
            DrawCircle(
                  monsters[i].getpos().x,
                  monsters[i].getpos().y,
                  par.dotSize,
                  par.clrmonsters
            );
         }
   }
   CloseWindow();

   return 0;
}
