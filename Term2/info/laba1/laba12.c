#include <stdio.h>

int main() {
  printf("Введите желаемое кол-во строк матрицы\n");
  int countstr; scanf("%d", &countstr);
  printf("Введите желаемое кол-во столбцов матрицы\n");
  int countstlb; scanf("%d", &countstlb);
  int G[countstr][countstlb]; //объявление массива
  
  printf("\n");
  
  for (int str=0; str<countstr;str++)
  {
    for (int stlb=0; stlb<countstlb;stlb++)
    {
      G[str][stlb]=str;
    }
  }
  for (int stro=0; stro<countstr; stro++)
  {
    for (int stolb=0; stolb<countstlb; stolb++)
    {
      printf("%d ", G[stro][stolb]);
    }
  printf("\n");
  }
}

