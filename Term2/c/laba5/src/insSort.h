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
