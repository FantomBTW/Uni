#include <iostream>
#include "raylib.h"
#include "funcs.hpp"
#include "classes.hpp"

int main() {
    InitWindow(800, 600, "dnd");
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        DrawText("Good!", 250, 280, 150, BLACK);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
