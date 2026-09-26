#include "mergesort.hpp"
#include <vector>

void mergerNSorter(
        std::vector<Row> &vec,
        int left,//т.к. мы работает с одним массивом, а не разными, берём подмассивы по индексам
        int right,//ну а это конец подмассива
        int sortIndex
    ){
    if (left >= right) return;//массивы длинной в 1 отсортированы

    int mid = left + (right - left)/2; //средний элемент чтоб взять середину как края
    
    mergerNSorter(vec, left, mid, sortIndex);
    mergerNSorter(vec, mid+1, right, sortIndex);
    
    merge(vec, sortIndex, left, mid, right); // склеиваем подмассивы, помним, что это как бы просто части массивов, но как бы массивы
}


void merge(
        std::vector<Row> &vec,
        int sortIndex,
        int left,
        int mid,
        int right
    ){
    //сначала создаём о
}


void mergeSort(std::vector<Row> &vec, int sortIndex){

}
