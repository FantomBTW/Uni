#include <stdio.h>

void prnarr(int arr[], int n){
   for (int i = 0; i < n; i++ ){
      printf("elem %d = %d\n", i, arr[i]);
   }
}
