<div align="center">

МИНИСТЕРСТВО ТРАНСПОРТА РОССИЙСКОЙ ФЕДЕРАЦИИ  
ФЕДЕРАЛЬНОЕ АГЕНТСТВО ЖЕЛЕЗНОДОРОЖНОГО ТРАНСПОРТА  
Государственное бюджетное образовательное учреждение  
высшего образования  
**«ПЕТЕРБУРГСКИЙ ГОСУДАРСТВЕННЫЙ УНИВЕРСИТЕТ  
ПУТЕЙ СООБЩЕНИЯ ИМПЕРАТОРА АЛЕКСАНДРА I»**  

Кафедра «ИНФОРМАЦИОННЫЕ И ВЫЧИСЛИТЕЛЬНЫЕ СИСТЕМЫ»  

---

Дисциплина: «Программирование C»

<br><br><br>
<br><br><br>

### О Т Ч Е Т

### по лабораторной работе № 4

</div>

<br><br><br>
<br><br><br>

<div align="right">
  <table align="right" style="border: none;">
    <tr>
      <td style="text-align: left; border: none;">
        Выполнил студент<br>
        Факультета АИТ<br>
        Группы ИВБ-515<br>
        Принял
      </td>
      <td style="text-align: right; border: none; vertical-align: bottom; padding-left: 50px;">
        Нартов С. А.<br>
        <br>
        <br>
        Носонов В.Ю.
      </td>
    </tr>
  </table>
</div>

<br><br><br>
<br><br><br>
<br><br><br>
<br><br><br><br><br>

<div align="center">
  Санкт-Петербург<br>  
  2026<br>
</div>


## Задача 1

    a) Вычислить (по формуле !) сколько времени, в воспринимаемом измерении, надо для перемещении 64 элементов Ханойской башни на современном компьютере.
    b) Добавить в программу код для подсчета числа произведенных перемещений, сравнить с формулой.
    c) Добавить в программу код для отображения номера уровня стека вызовов и аргументов, переданных на этот уровень
    d) Написать и отладить программу , в которой надо перенести элементы с A на С, но передвигать можно только с А=>B, B=>C и C=>B, B=>A, но не А=>C или C=>A.

    e) Написать и отладить программу , в которой надо перенести элементы с A на B, но передвигать можно только с А=>B, B=>C и C=>B, B=A, но не А=>C или C=>A.

Программа должна отображать состояние башен после каждого перемещения.

Листинг

main.c
```c
#include <stdio.h>
#include <math.h>
#include "head.h"



int main() {
   double m64 = pow(2, 64) - 1;
   double sec = m64 / 1e9;
   double years = sec / (60.0 * 60 * 24 * 365);
   printf("a) time for 64: ~%.2f yrs\n\n", years);
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
```

head.h
```c
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
```

param.h
```c
#pragma once

#define MAX 10
int nA = 0, nB = 0, nC = 0;
int A[MAX], B[MAX], C[MAX];
long long moves_cnt = 0;
```

вывод
```shell
a) time for 64: ~584.94 yrs

task d:  A -> C ===
  A: 3 2 1 
  B: 
  C: 

Level 0: hanoi_res(n=3, A->C)
Level 1: hanoi_res(n=2, A->C)
Level 2: hanoi_res(n=1, A->C)
Level 3: hanoi_res(n=0, A->C)
move 1: disk 1 A -> B
  A: 3 2 
  B: 1 
  C: 

Level 3: hanoi_res(n=0, C->A)
move 2: disk 1 B -> C
  A: 3 2 
  B: 
  C: 1 

Level 3: hanoi_res(n=0, A->C)
move 3: disk 2 A -> B
  A: 3 
  B: 2 
  C: 1 

Level 2: hanoi_res(n=1, C->A)
Level 3: hanoi_res(n=0, C->A)
move 4: disk 1 C -> B
  A: 3 
  B: 2 1 
  C: 

Level 3: hanoi_res(n=0, A->C)
move 5: disk 1 B -> A
  A: 3 1 
  B: 2 
  C: 

Level 3: hanoi_res(n=0, C->A)
move 6: disk 2 B -> C
  A: 3 1 
  B: 
  C: 2 

Level 2: hanoi_res(n=1, A->C)
Level 3: hanoi_res(n=0, A->C)
move 7: disk 1 A -> B
  A: 3 
  B: 1 
  C: 2 

Level 3: hanoi_res(n=0, C->A)
move 8: disk 1 B -> C
  A: 3 
  B: 
  C: 2 1 

Level 3: hanoi_res(n=0, A->C)
move 9: disk 3 A -> B
  A: 
  B: 3 
  C: 2 1 

Level 1: hanoi_res(n=2, C->A)
Level 2: hanoi_res(n=1, C->A)
Level 3: hanoi_res(n=0, C->A)
move 10: disk 1 C -> B
  A: 
  B: 3 1 
  C: 2 

Level 3: hanoi_res(n=0, A->C)
move 11: disk 1 B -> A
  A: 1 
  B: 3 
  C: 2 

Level 3: hanoi_res(n=0, C->A)
move 12: disk 2 C -> B
  A: 1 
  B: 3 2 
  C: 

Level 2: hanoi_res(n=1, A->C)
Level 3: hanoi_res(n=0, A->C)
move 13: disk 1 A -> B
  A: 
  B: 3 2 1 
  C: 

Level 3: hanoi_res(n=0, C->A)
move 14: disk 1 B -> C
  A: 
  B: 3 2 
  C: 1 

Level 3: hanoi_res(n=0, A->C)
move 15: disk 2 B -> A
  A: 2 
  B: 3 
  C: 1 

Level 2: hanoi_res(n=1, C->A)
Level 3: hanoi_res(n=0, C->A)
move 16: disk 1 C -> B
  A: 2 
  B: 3 1 
  C: 

Level 3: hanoi_res(n=0, A->C)
move 17: disk 1 B -> A
  A: 2 1 
  B: 3 
  C: 

Level 3: hanoi_res(n=0, C->A)
move 18: disk 3 B -> C
  A: 2 1 
  B: 
  C: 3 

Level 1: hanoi_res(n=2, A->C)
Level 2: hanoi_res(n=1, A->C)
Level 3: hanoi_res(n=0, A->C)
move 19: disk 1 A -> B
  A: 2 
  B: 1 
  C: 3 

Level 3: hanoi_res(n=0, C->A)
move 20: disk 1 B -> C
  A: 2 
  B: 
  C: 3 1 

Level 3: hanoi_res(n=0, A->C)
move 21: disk 2 A -> B
  A: 
  B: 2 
  C: 3 1 

Level 2: hanoi_res(n=1, C->A)
Level 3: hanoi_res(n=0, C->A)
move 22: disk 1 C -> B
  A: 
  B: 2 1 
  C: 3 

Level 3: hanoi_res(n=0, A->C)
move 23: disk 1 B -> A
  A: 1 
  B: 2 
  C: 3 

Level 3: hanoi_res(n=0, C->A)
move 24: disk 2 B -> C
  A: 1 
  B: 
  C: 3 2 

Level 2: hanoi_res(n=1, A->C)
Level 3: hanoi_res(n=0, A->C)
move 25: disk 1 A -> B
  A: 
  B: 1 
  C: 3 2 

Level 3: hanoi_res(n=0, C->A)
move 26: disk 1 B -> C
  A: 
  B: 
  C: 3 2 1 

Level 3: hanoi_res(n=0, A->C)
b) formul 3^n-1: 26, fact: 26

task e: A -> B 
  A: 3 2 1 
  B: 
  C: 

Level 0: hanoi_res(n=3, A->B)
Level 1: hanoi_res(n=2, A->C)
Level 2: hanoi_res(n=1, A->C)
Level 3: hanoi_res(n=0, A->C)
move 1: disk 1 A -> B
  A: 3 2 
  B: 1 
  C: 

Level 3: hanoi_res(n=0, C->A)
move 2: disk 1 B -> C
  A: 3 2 
  B: 
  C: 1 

Level 3: hanoi_res(n=0, A->C)
move 3: disk 2 A -> B
  A: 3 
  B: 2 
  C: 1 

Level 2: hanoi_res(n=1, C->A)
Level 3: hanoi_res(n=0, C->A)
move 4: disk 1 C -> B
  A: 3 
  B: 2 1 
  C: 

Level 3: hanoi_res(n=0, A->C)
move 5: disk 1 B -> A
  A: 3 1 
  B: 2 
  C: 

Level 3: hanoi_res(n=0, C->A)
move 6: disk 2 B -> C
  A: 3 1 
  B: 
  C: 2 

Level 2: hanoi_res(n=1, A->C)
Level 3: hanoi_res(n=0, A->C)
move 7: disk 1 A -> B
  A: 3 
  B: 1 
  C: 2 

Level 3: hanoi_res(n=0, C->A)
move 8: disk 1 B -> C
  A: 3 
  B: 
  C: 2 1 

Level 3: hanoi_res(n=0, A->C)
move 9: disk 3 A -> B
  A: 
  B: 3 
  C: 2 1 

Level 1: hanoi_res(n=2, C->B)
Level 2: hanoi_res(n=1, C->A)
Level 3: hanoi_res(n=0, C->A)
move 10: disk 1 C -> B
  A: 
  B: 3 1 
  C: 2 

Level 3: hanoi_res(n=0, A->C)
move 11: disk 1 B -> A
  A: 1 
  B: 3 
  C: 2 

Level 3: hanoi_res(n=0, C->A)
move 12: disk 2 C -> B
  A: 1 
  B: 3 2 
  C: 

Level 2: hanoi_res(n=1, A->B)
Level 3: hanoi_res(n=0, A->C)
move 13: disk 1 A -> B
  A: 
  B: 3 2 1 
  C: 

Level 3: hanoi_res(n=0, C->B)
e) moves theory 2*3^(n-1)-1: 17, fact: 13
```

## Задача 2


