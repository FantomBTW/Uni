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
