void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void bblesort(int arr[], int n){
   int last_swap = 1;
   for (int i; i-1 < n; i++){
      if (arr[i] < arr[i+1]){
         swap(&arr[i], &arr[i+1]);
      }
   }
}
