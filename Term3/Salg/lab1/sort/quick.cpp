#include "quick.hpp"
#include <cmath>
#include "../csv/csv.hpp"
#include "swap.hpp"

void quickSort(std::vector<Row>& vec, int sortIndex) {
    //проверка на столбец, чтоб не сравнивать строки
    bool isNum = !std::isnan(vec[0].numeric[sortIndex]);
    quickSorter(vec, sortIndex, 0, static_cast<int>(vec.size()) - 1, isNum);
}

//  идём слева направо, всё <= pilot перемещаем на место последнего элемента,
//  что меньше
int part(std::vector<Row>& vec, int sortIndex, int left, int right, bool isNum) {
    Row pilot = vec[right];
    int i = left - 1; // левая грань

    for (int j = left; j < right; j++) {
        if (cmp(vec[j], pilot, sortIndex, isNum) <= 0) {
            i++;
            swap(vec[i], vec[j]);
        }
    }

    // ставим pilot-а, т.к. всё что слева меньше чем он
    swap(vec[i + 1], vec[right]);
    return i + 1; // возвращаем его индекс
}

void quickSorter(std::vector<Row>& vec, int sortIndex, int left, int right, bool isNum) {
    if (left >= right) return;
    //здесь мы сортируем по пилоту
    int pilot = part(vec, sortIndex, left, right, isNum);
    // после чего мы сортируем вокруг текущего пилота
    quickSorter(vec, sortIndex, left, pilot - 1, isNum);
    quickSorter(vec, sortIndex, pilot + 1, right, isNum);
}
