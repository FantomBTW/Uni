#include <vector>
#include <cmath>
#include "../csv/csv.hpp"
#include "swap.hpp"

void heaps(std::vector<Row>& vec, int n, int i, int sortIndex, bool isNum){
    int largest = i; //root is largest 4now
    int left = 2*i+1;
    int right = 2*i+2;

    //ищем, какой элемент из текущих максимальный
    if (left < n/*we dont out of range*/
            &&
            cmp(vec[left], vec[largest], sortIndex, isNum) > 0
    ) largest = left;

    if (
            right < n
            &&
            cmp(vec[right], vec[largest], sortIndex, isNum) > 0
    ) largest = right;

    //если мы меняли индекс максимального, меняем максимальный с корнем текущей ветви
    //после чего предыдущий корень просеиваем вниз и ищем внизу новый корень
    if (largest != i){
        swap(vec[i], vec[largest]);
        heaps(vec, n, largest, sortIndex, isNum);
    }
}

void heapSort(std::vector<Row>& vec, int sortIndex){
    //проверка на столбец, чтоб не сравнивать строки
    bool isNum = !std::isnan(vec[0].numeric[sortIndex]);

    int n = vec.size();
    for (int i = n/2 - 1; i >= 0; i--){
        heaps(vec, n, i, sortIndex, isNum);//таким образом мы перемещаем максимум в самый "верх"
    }

    for (int i = n-1; i > 0; i--){
        swap(vec[0], vec[i]);//кидаем верхушку в кэш
        heaps(vec, i, 0, sortIndex, isNum);//таким образом мы перемещаем максимум в самый "верх"
    }
}
