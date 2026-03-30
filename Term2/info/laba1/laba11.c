#include <stdio.h>

int main() {
  printf("Введите желаемую длину массива\n");
  int q; scanf("%d", &q);
  int T[q];
  
  printf("введите значение T[i]\n");
  for (int i = 0; i<q; i++){
    printf("T[%d]=", i+1);
    scanf("%d", T+i);
  }
  
  for (int i = 0; i<q; i++){
    printf("%d ", T[i]*T[i]*i);
  }
}
