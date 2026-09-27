#include "lexisort.hpp"
#include <string>
#include "swap.hpp"

//лексикографическая сортировка столбца строк selection sort-ом:
//  на каждой итерации ищем минимальную строку (по std::string operator<)
//  и ставим её на текущую позицию
void lexiSort(std::vector<Row>& vec, int sortIndex) {
    for (int i = 0; i < static_cast<int>(vec.size()) - 1; i++) {
        //индекс минимальной строки в неотсортированной части
        int minIndex = i;

        for (int j = i + 1; j < static_cast<int>(vec.size()); j++) {
            if (vec[j].cells[sortIndex] < vec[minIndex].cells[sortIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swap(vec[i], vec[minIndex]);
        }
    }
}
