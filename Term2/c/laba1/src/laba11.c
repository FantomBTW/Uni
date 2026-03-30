#include "laba11.h"
#include <stdio.h>

int main()
{
  char h[50]="Hello ";
  char w[] = "world!";
  h = strcat(h, w);
  printf("%s", h);
  return 0;
}
