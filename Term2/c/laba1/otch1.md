# Задание 1

1. Постановка задачи
   
   В файле содержится информация типа «футбольный клуб» в следующем виде: название, страна происхождения, годы побед. Считать информацию из файла, в другой файл записать информацию только о клубах из Аргентины.
   
   ```textile
   Бока Хуниорс; Аргентина; 2000, 2001, 2003, 2005
   Реал Мадрид; Испания; 1956, 1957, 1958, 1959, 1960, 1966, 1998, 2000, 2002, 2014, 2016, 2017, 2018
   Ривер Плейт; Аргентина; 1986, 1996, 2015, 2018
   Бавария; Германия; 1974, 1975, 1976, 2001, 2013, 2020
   Индепендьенте; Аргентина; 1972, 1973, 1974, 1975, 1984
   Манчестер Юнайтед; Англия; 1968, 1999, 2008
   Расинг; Аргентина; 1967
   Ливерпуль; Англия; 1977, 1978, 1981, 1984, 2005, 2019
   Ньюэллс Олд Бойз; Аргентина; нет
   Эстудиантес; Аргентина; 1968, 1969, 1970
   Ювентус; Италия; 1985, 1996
   ```

2. Код программы
   
   ```c
   //laba11.c
   #include "laba11.h"
   
   int main()
   {
     perepis();
     return 0;
   }
   ```
   
   Заголовочный файл
   
   ```c
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
   ```

3. Отладка

![](/home/fantom/.config/marktext/images/2026-02-17-00-11-43-image.png)



# Задание 2

1. постановка задачи
   
   ![](/home/fantom/.config/marktext/images/2026-02-28-20-41-58-image.png)

2. Код функций
   
   ```c
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
   ```
   
   
