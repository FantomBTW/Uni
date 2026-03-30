#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE * f=fopen("zachlist.txt","w");

  if (!f)exit(1);
  fprintf(f,"Нартов Сергей 2007 отл\n");
  fclose(f);

  f = open("zachlist.txt","a");
  if(!f)exit(1);
  fprintf(f,"Осипов Иван 2007 отл\n");
  fprintf(f,"Сергеева Елизавета 2007 отл\n");
  
  return 0;
}
