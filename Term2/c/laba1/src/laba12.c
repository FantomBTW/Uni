#include <stdio.h>
#include <stdlib.h>
#include "laba12.h"

int main ()
{
  char str1[50] = "Hello ";
  char str2[] = "world!";
  strcat(str1,str2);
  printf("%s", str1);
}
