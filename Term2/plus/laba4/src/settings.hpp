#pragma once
#include "raylib.h"

#define N 3

struct settings{
   int width = 1920;
   int height = 1080;
   Color clrmonsters = RED;
   Color clrheroes = BLUE;
   float dotSize = 5.0f * N;
};
