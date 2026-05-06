#include "massives.h"
#include <stdio.h>

int main(){
   int unsorted[] = {1,5,4,77,23,5,5};
   int size = sizeof(unsorted)/sizeof(unsorted[0]);

   prnarr(unsorted, size);
   
   int choise = 0;
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
