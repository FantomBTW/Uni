#include <stdio.h>
#include <stdlib.h>


int string_eq(char *s1, char *s2)
{
  while (*s1 == *s2)
  {
    if (*s1=='\0' && *s2 == '\0'){return 1;}
    s1++;s2++;
  }
  return 0;
}


int getcountry(char strok[])
{
  int tekuchsymb = 0;
  int flag = 0;
  char country[20];
  int lastchar = 0;
  
  while (strok[tekuchsymb] != '\0')
  {
    if (strok[tekuchsymb] == ';')
    {
      flag++;
    } else if (flag == 1) {
      country[lastchar] = strok[tekuchsymb];
      country[lastchar+1] = '\0';
      lastchar++;
    }

    tekuchsymb++;
  }

  if (string_eq(country, " Аргентина"))
  {
    return 1;
  }
  return 0;
}


int perepis()
{
  FILE * f=fopen("clubs","r");
  if (!f)exit(1);
  
  FILE * argen=fopen("argentina","w");
  if (!argen)exit(1);

  char buffer[256];

  int argentina; 
  
  while(fgets(buffer, 256, f))
  {
    argentina = getcountry(buffer);
    if (argentina == 1)
    {
      fprintf(argen, "%s", buffer);
      fprintf(argen,"\n");
    }
  }

  return 0;
}
