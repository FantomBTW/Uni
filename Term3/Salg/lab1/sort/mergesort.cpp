#include "mergesort.hpp"
#include <vector>
#include <cmath>
#include <iostream>

//forward declaration для рекурсивной версии
void mergeSortRecursive(std::vector<Row>& vec, int left, int right, int sortIndex);

//merge:
//  слияние двух отсортированных частей в один отсортированный массив
// Делает stable sort (<=), если элементы равны — берём левый, сохраняя порядок
void merge(std::vector<Row>& vec, int left, int mid, int right, int sortIndex) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    //копируем данные в временные массивы
    std::vector<Row> L(n1);
    std::vector<Row> R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = vec[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = vec[mid + 1 + j];
    }

    //сливаем L и R обратно в vec, сравнивая по sortIndex
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        //<= — stable sort: при равенстве берём левый элемент
        if (L[i].numeric[sortIndex] <= R[j].numeric[sortIndex]) {
            vec[k] = L[i];
            i++;
        } else {
            vec[k] = R[j];
            j++;
        }
        k++;
    }

    //копируем оставшиеся элементы из L
    while (i < n1) {
        vec[k] = L[i];
        i++;
        k++;
    }

    //копируем оставшиеся элементы из R
    while (j < n2) {
        vec[k] = R[j];
        j++;
        k++;
    }
}

//mergeSort:
//  рекурсивно делим массив пополам, пока не останется 1 элемент, затем слиянием объединяем
// Отличие от bubbleSort/selectionSort/insertionSort:
//   - O(n log n) против O(n²) — значительно быстрее на больших массивах
//   - стабильный (сохраняет порядок равных элементов)
//   - требует O(n) дополнительной памяти для временных массивов
//   - рекурсивный (разделяй и властвуй): divide → conquer → merge
void mergeSort(std::vector<Row>& vec, int sortIndex) {
    //проверка на столбец, чтоб не сравнивать строки
    if (std::isnan(vec[0].numeric[sortIndex])) {
        std::cerr << "column isnt numeric";
        exit(1);
    }

    //вызываем рекурсивную версию
    mergeSortRecursive(vec, 0, vec.size() - 1, sortIndex);
}

//вспомогательная рекурсивная функция
void mergeSortRecursive(std::vector<Row>& vec, int left, int right, int sortIndex) {
    //базовый случай: 0 или 1 элемент — уже отсортирован
    if (left < right) {
        //делим пополам (защита от переполнения при left + right)
        int mid = left + (right - left) / 2;

        //рекурсивно сортируем левую и правую половины
        mergeSortRecursive(vec, left, mid, sortIndex);
        mergeSortRecursive(vec, mid + 1, right, sortIndex);

        //слияние двух отсортированных половин
        merge(vec, left, mid, right, sortIndex);
    }
}
