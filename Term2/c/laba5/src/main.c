#include "bble.h"
#include "prn.h"

int main(){
   int unsorted[] = {1,5,4,77,23,5,5};
   int size = sizeof(unsorted)/sizeof(int);

   prnarr(unsorted, size)
   
   bblesort(unsorted, size);
}
