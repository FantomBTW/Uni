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
