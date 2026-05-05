#include <stdio.h>
#include <limits.h>

typedef int (*Cond)(int);

int is_even(int x)  { return x % 2 == 0; }
int is_pos(int x)   { return x > 0; }

int rec_max(int a[], int n, Cond f) {
    if (n == 0) return INT_MIN;
    int m = rec_max(a, n - 1, f);
    return (f(a[n - 1]) && a[n - 1] > m) ? a[n - 1] : m;
}

int rec_min(int a[], int n, Cond f) {
    if (n == 0) return INT_MAX;
    int m = rec_min(a, n - 1, f);
    return (f(a[n - 1]) && a[n - 1] < m) ? a[n - 1] : m;
}

int rec_sum(int a[], int n, Cond f) {
    if (n == 0) return 0;
    return rec_sum(a, n - 1, f) + (f(a[n - 1]) ? a[n - 1] : 0);
}

int rec_prod(int a[], int n, Cond f) {
    if (n == 0) return 1;
    return rec_prod(a, n - 1, f) * (f(a[n - 1]) ? a[n - 1] : 1);
}

int main() {
    int arr[] = {4, -2, 7, 8, -1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("src massive: ");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    printf("\neven numbers\n");
    printf("Max: %d | Min: %d\n", rec_max(arr, n, is_even), rec_min(arr, n, is_even));
    printf("Sum: %d | Prod: %d\n", rec_sum(arr, n, is_even), rec_prod(arr, n, is_even));

    printf("\npositive numbers\n");
    printf("Max: %d | Sum: %d\n", rec_max(arr, n, is_pos), rec_sum(arr, n, is_pos));

    return 0;
}
