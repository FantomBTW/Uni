#include <stdio.h>

int string_eq(char *s1, char *s2)
{
  while (*s1 != '\0')
  {
    if (*s1 != *s2){s1++;s2++;}
    else{return 1;}
  }
  return 0;
}
