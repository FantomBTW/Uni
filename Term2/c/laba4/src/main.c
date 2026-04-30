#include <stdio.h>
#include <math.h>
#include "head.h"



int main() {
   double m64 = pow(2, 64) - 1;
   double sec = m64 / 1e9;
   double years = sec / (60.0 * 60 * 24 * 365);
   printf("a) time for 64: ~%.2f лет\n\n", years);
   int n = 3;

   printf("task d:  A -> C ===\n");
   init(n);
   moves_cnt = 0;
   print_towers();
   hanoi_res(n, 'A', 'C', 0);
   
   long long formula_dc = (long long)pow(3, n) - 1;
   printf("b) formul 3^n-1: %lld, fact: %lld\n\n", formula_dc, moves_cnt);

   // п. e) Перенос A -> B с ограничениями
   printf("task e: A -> B \n");
   init(n);
   moves_cnt = 0;
   print_towers();
   hanoi_res(n, 'A', 'B', 0);
   
   long long formula_ab = 2 * (long long)pow(3, n-1) - 1; // формула для A->B
   printf("e) moves theory 2*3^(n-1)-1: %lld, fact: %lld\n", formula_ab, moves_cnt);

   return 0;
}
