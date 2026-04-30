#include <stdio.h>
#include "param.h"

void init(int n) {
   nA = n; nB = 0; nC = 0;
   for(int i=0; i<n; i++) A[i] = n - i;
}

void print_towers() {
   printf("  A: "); for(int i=0; i<nA; i++) printf("%d ", A[i]);
   printf("\n  B: "); for(int i=0; i<nB; i++) printf("%d ", B[i]);
   printf("\n  C: "); for(int i=0; i<nC; i++) printf("%d ", C[i]);
   printf("\n\n");
}

void do_move(int disk, char from, char to) {
   moves_cnt++;
   if (from == 'A') nA--;
   else if (from == 'B') nB--;
   else nC--;

   if (to == 'A') A[nA++] = disk;
   else if (to == 'B') B[nB++] = disk;
   else C[nC++] = disk;

   printf("move %lld: disk %d %c -> %c\n", moves_cnt, disk, from, to);
   print_towers();
}

// (c, d, e)
void hanoi_res(int n, char src, char dst, int level) {
   printf("Level %d: hanoi_res(n=%d, %c->%c)\n", level, n, src, dst);
   if (n == 0) return;
   
   char aux = 'A' + 'B' + 'C' - src - dst; // третий стержень

   if (src == 'A' && dst == 'C') {
     hanoi_res(n-1, src, dst, level+1);
     do_move(n, src, aux); // A->B
     hanoi_res(n-1, dst, src, level+1);
     do_move(n, aux, dst); // B->C
     hanoi_res(n-1, src, dst, level+1);
   } else if (src == 'C' && dst == 'A') {
     hanoi_res(n-1, src, dst, level+1);
     do_move(n, src, aux); // C->B
     hanoi_res(n-1, dst, src, level+1);
     do_move(n, aux, dst); // B->A
     hanoi_res(n-1, src, dst, level+1);
   } else {
     hanoi_res(n-1, src, aux, level+1);
     do_move(n, src, dst);
     hanoi_res(n-1, aux, dst, level+1);
   }
}

