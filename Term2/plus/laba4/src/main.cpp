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
