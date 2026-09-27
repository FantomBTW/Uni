#include "basesorts.hpp"
#include <vector>
#include <cmath>
#include <iostream>
#include "swap.hpp"
#include "quick.hpp"
#include "mergesort.hpp"
#include "heapsort.hpp"

//insertionSort:
//  двигаем влево до упора
void insertionSort(std::vector<Row>& vec, int sortIndex) {
    //проверка на столбец, чтоб не сравнивать строки
    bool isNum = !std::isnan(vec[0].numeric[sortIndex]);

    //перебираем все элементы со второго
    for (int i = 1; i < static_cast<int>(vec.size()); i++) {
        //запоминаем, что нам надо
        Row key = vec[i];
        int j = i - 1;

        //двигаем отсортированные элементы вправо
        while (j >= 0 && cmp(vec[j], key, sortIndex, isNum) > 0) {
            vec[j + 1] = vec[j];
            j--;
        }
        //сохраняем, что нам надо
        vec[j + 1] = key;
    }
}

//selectionSort:
//  находим минимальный элемент и меняем его с первым несортированным
void selectionSort(std::vector<Row>& vec, int sortIndex) {
    //проверка на столбец, чтоб не сравнивать строки
    bool isNum = !std::isnan(vec[0].numeric[sortIndex]);

    for (int i = 0; i < static_cast<int>(vec.size()) - 1; i++) {
        //индекс минимального элемента в неотсортированной части
        int minIndex = i;

        //ищем min
        for (int j = i + 1; j < static_cast<int>(vec.size()); j++) {
            if (cmp(vec[j], vec[minIndex], sortIndex, isNum) < 0) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swap(vec[i], vec[minIndex]);
        }
    }
}

//bubbleSort:
//  соседние элементы меняются местами, максимум "всплывает"
void bubbleSort(std::vector<Row>& vec, int sortIndex) {
    //проверка на столбец, чтоб не сравнивать строки
    bool isNum = !std::isnan(vec[0].numeric[sortIndex]);

    //проходим по массиву, за каждый проход минимум 1 элемент встаёт на своё место (в конец)
    for (int i = 0; i < static_cast<int>(vec.size()) - 1; ++i) {
        //флаг, что swaps не было — массив уже отсортирован, можно выйти
        bool swapped = false;

        //последние i элементов уже "всплыли"
        for (int j = 0; j < static_cast<int>(vec.size()) - i - 1; ++j) {
            //если слева больше чем справа - меняем
            if (cmp(vec[j], vec[j + 1], sortIndex, isNum) > 0) {
                swap(vec[j], vec[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }
}

void dispatchSort(std::vector<Row>& vec, int sortIndex, int sortMethod) {
    switch (sortMethod) {
        case 0: selectionSort(vec, sortIndex); break;
        case 1: bubbleSort(vec, sortIndex); break;
        case 2: insertionSort(vec, sortIndex); break;
        case 3: mergeSort(vec, sortIndex); break;
        case 4: heapSort(vec, sortIndex); break;
        case 5: quickSort(vec, sortIndex); break;
        default: break;
    }
}
