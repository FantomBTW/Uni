#include "basesorts.hpp"
#include <vector>
#include <cmath>
#include <iostream>

void swap(Row& a, Row& b) {
    Row temp = a;
    a = b;
    b = temp;
}

//insertionSort:
//  двигаем влево до упора
void insertionSort(std::vector<Row>& vec, int sortIndex) {
    //проверка на столбец, чтоб не сравнивать строки
    if (std::isnan(vec[0].numeric[sortIndex])) {
        std::cerr << "column isnt numeric";
        exit(1);
    }

    //перебираем все элементы со второго
    for (int i = 1; i < vec.size(); i++) {
        //запоминаем, что нам надо
        Row key = vec[i];
        int j = i - 1;

        //двигаем отсортированные элементы вправо
        while (j >= 0 && vec[j].numeric[sortIndex] > key.numeric[sortIndex]) {
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
    if (std::isnan(vec[0].numeric[sortIndex])) {
        std::cerr << "column isnt numeric";
        exit(1);
    }

    for (int i = 0; i < vec.size() - 1; i++) {
        //индекс минимального элемента в неотсортированной части
        int minIndex = i;

        //ищем min
        for (int j = i + 1; j < vec.size(); j++) {
            if (vec[j].numeric[sortIndex] < vec[minIndex].numeric[sortIndex]) {
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
    if (std::isnan(vec[0].numeric[sortIndex])) {
        std::cerr << "column isnt numeric";
        exit(1);
    }

    //проходим по массиву, за каждый проход минимум 1 элемент встаёт на своё место (в конец)
    for (int i = 0; i < vec.size() - 1; ++i) {
        //флаг, что swaps не было — массив уже отсортирован, можно выйти
        bool swapped = false;

        //последние i элементов уже "всплыли"
        for (int j = 0; j < vec.size() - i - 1; ++j) {
            //если слева больше чем справа - меняем
            if (vec[j].numeric[sortIndex] > vec[j + 1].numeric[sortIndex]) {
                swap(vec[j], vec[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }
}
