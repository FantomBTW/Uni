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

### по лабораторной работе № 5

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


## Задача
1.	Создать функцию сортировки «пузырьком» итерационную и рекурсивную, модифицировать метод, передвинув нижнюю границу на место последнего swap. Усовершенствуйте алгоритм, применив способ “перемешивание” где перетаскивается не только тяжелый элемент вниз, но и легкий вверх.␍
2.	Создать функцию сортировки «вставками», для поиска места вставки в отсортированную часть массива применять функцию двоичного поиска.␍
3.	Создать функцию быстрой «qsort» сортировки, отличной от приведённого на лекции.␍
    Во всех функциях:␍
    a)	применять указатели (не индексы);␍
    b)	для сравнения элементов, применять функцию (свою, не такую как в лекции) передаваемую как указатель, в качестве параметра функции сортировки;␍
    c)	посчитать количество сравнений элементов, перестановок и (желательно) глубину рекурсии.␍

Листинг

main.c
```c
#include "incls.h"
#include <stdio.h>

int main(){
   int unsorted[] = {1,5,4,77,23,5,5};
   int size = sizeof(unsorted)/sizeof(unsorted[0]);

   prnarr(unsorted, size);
   
   int choise = 0;
   printf("choose sort\n1:bblesort\n2:bin_insertion_sort");
   scanf("%d", &choise);
   switch (choise) {
      case 1:
         bblesort(unsorted, size);
         break;
      case 2:
         bin_insertion_sort(unsorted, size);
         break;
   }

   printf("\n");
   prnarr(unsorted, size);
}
```

incls.h
```c
#include "bble.h"
#include "insSort.h"
#include "prn.h"
#include "qsort.h"
```

bble.h
```c
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void bblesort(int arr[], int n){
   int right = n-1;
   int last_swap = 1;

   while (right > 0) {
      last_swap = 0;
      for (int i = 0; i < right; i++){
         if (arr[i] > arr[i+1]){
            swap(&arr[i], &arr[i+1]);
            last_swap = i;
         }
      }
      right = last_swap;
   }
}
```

insSort.h
```c
int bin_search_pos(int arr[], int right, int key) {
   int left = 0;
   while (left <= right) {
      int mid = (left + right) / 2;
      if (arr[mid] <= key)
         left = mid + 1;
      else
         right = mid - 1;
   }
   return left;
}

void bin_insertion_sort(int arr[], int n) {
   int key = 0;
   int pos = 0;
   for (int i = 1; i < n; i++) {
      key = arr[i];
      pos = bin_search_pos(arr, i - 1, key);

      for (int j = i; j > pos; j--) {
         arr[j] = arr[j - 1];
      }
      arr[pos] = key;
   }
}
```

qsort.h
```c
#include <stdio.h>
#include "struct.h"

void swap(int *a, int *b, qsort_stats_t *stats){
    int tmp = *a;
    *a = *b;
    *b = tmp;
    stats->swaps++;
}

int compare_ints(const int *a, const int *b){
    const int *x = a;
    const int *y = b;

    return (*x > *y) - (*x < *y);
}

int *partition(
    int *l, int *r,
    int (*cmp)(const int *, const int *),
    qsort_stats_t *stats
){
    int *opor = r;
    int *i = l;

    for (int *j = l; j < r; j++) {
        stats->comparisons++;

        if (cmp(j, opor) < 0) {
            swap(i, j, stats);
            i++;
        }
    }

    swap(i, opor, stats);

    return i;
}

void quick_sort_recursive(
    int *left,
    int *right,
    int (*cmp)(const int *, const int *),
    qsort_stats_t *stats,
    unsigned long depth
){
    if (left >= right)return;

    if (depth > stats->recursion_depth) {
        stats->recursion_depth = depth;
    }

    int *pivot = partition(left, right, cmp, stats);

    quick_sort_recursive(left, pivot - 1, cmp, stats, depth + 1);

    quick_sort_recursive(pivot + 1, right, cmp, stats, depth + 1);
}

void quick_sort(
        int *begin, int *end, 
        int (*cmp)(const int *, const int *), 
        qsort_stats_t *stats
){
    stats->comparisons = 0;
    stats->swaps = 0;
    stats->recursion_depth = 0;

    quick_sort_recursive(begin, end - 1, cmp, stats, 1);
}
```
