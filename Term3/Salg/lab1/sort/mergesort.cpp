#include "mergesort.hpp"
#include <cmath>
#include <vector>
#include "swap.hpp"

void mergerNSorter(
        std::vector<Row> &vec,
        int left,//т.к. мы работает с одним массивом, а не разными, берём подмассивы по индексам
        int right,//ну а это конец подмассива
        int sortIndex,
        bool isNum
    ){
    if (left >= right) return;//массивы длинной в 1 отсортированы

    int mid = left + (right - left)/2; //средний элемент чтоб взять середину как края

    mergerNSorter(vec, left, mid, sortIndex, isNum);
    mergerNSorter(vec, mid+1, right, sortIndex, isNum);

    merge(vec, sortIndex, left, mid, right, isNum); // склеиваем подмассивы, помним, что это как бы просто части массивов, но как бы массивы
}


void merge(
        std::vector<Row> &vec,
        int sortIndex,
        int left,
        int mid,
        int right,
        bool isNum
    ){
    //размеры половин
    int n1 = mid - left + 1;
    int n2 = right - mid;

    //"бэкапим"
    std::vector<Row> L(n1);
    std::vector<Row> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = vec[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = vec[mid + 1 + j];

    int leftPerebor = 0;
    int rightPerebor = 0;
    int global = left;
    while (leftPerebor < n1 && rightPerebor < n2) {
        //если левый элемент меньше, кидаем его в глобалку
        if (cmp(L[leftPerebor], R[rightPerebor], sortIndex, isNum) <= 0)
            vec[global++] = L[leftPerebor++];
        //иначе кидаем из правого массива
        else
            vec[global++] = R[rightPerebor++];
    }

    //если один массив опустел, второй докидываем до упора, он итак отсортирован
    while (leftPerebor < n1)
        vec[global++] = L[leftPerebor++];
    while (rightPerebor < n2)
        vec[global++] = R[rightPerebor++];
}


void mergeSort(std::vector<Row> &vec, int sortIndex){
    //абстракция над mergerNSorter
    //все сортировки запускаются через vec и sortIndex, а mergerNSorter рекурсивный, он так не может
    //проверка на столбец, чтоб не сравнивать строки
    bool isNum = !std::isnan(vec[0].numeric[sortIndex]);
    mergerNSorter(vec, 0, static_cast<int>(vec.size()) - 1, sortIndex, isNum);
}
