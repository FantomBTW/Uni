#include <stdio.h>
#include <stdlib.h>


int strlen(char *strok)
{
  int tekuch = 0;
  while(strok[tekuch] != '\0')
  {
    tekuch++;
  }
  return  tekuch;
}


char * strcpy(char *cpy,char *src)
{
  int i = 0;
  while (src[i] != '\0') {
    cpy[i] = src[i];
    i++;
  }
  cpy[i] = '\0';
  return cpy;
}


char * strcat(char * bo, char * ao)
{
  int lbo = strlen(bo);
  int iao = 0;

  while(ao[iao] != '\0')
  {
    bo[lbo+iao] = ao[iao];
    iao++;
  }
  bo [lbo + iao] = '\0';
  
  return bo;
}


int strcmp(char * str1, char * str2)
{
  int index = 0;
  while (str1[index] != '\0' && str2[index] != '\0' && str1[index] == str2[index])
  {
    index++;
  }
  if (str1[index] == '\0' && str2[index] == '\0')return 0;

  if (str1[index] > str2[index])return 1;
  else return -1;
}


char *strchr(char *str, int c)
{
  int index = 0;
  while (str[index] != '\0')
  {
    if (str[index] == char(c)){return str+index;}
    index++;
  }

  return NULL;
}
