#pragma once
#include "raylib.h"

#define N 1

struct settings{
   int width = 800;
   int height = 600;
   Color clrmonsters = RED;
   Color clrheroes = BLUE;
   float dotSize = 5.0f * N;
};
