#include "quick.hpp"
#include "../csv/csv.hpp"
#include "swap.hpp"

void quickSort(std::vector<Row>& vec, int sortIndex) {
    quickSorter(vec, sortIndex, 0, vec.size() - 1);
}

//  идём слева направо, всё <= pilot перемещаем на место последнего элемента, 
//  что меньше
int part(std::vector<Row>& vec, int sortIndex, int left, int right) {
    double pilot = vec[right].numeric[sortIndex];
    int i = left - 1; // левая грань

    for (int j = left; j < right; j++) {
        if (vec[j].numeric[sortIndex] <= pilot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }

    // ставим pilot-а, т.к. всё что слева меньше чем он
    swap(vec[i + 1], vec[right]);
    return i + 1; // возвращаем его индекс
}

void quickSorter(std::vector<Row>& vec, int sortIndex, int left, int right) {
    if (left >= right) return;
    //здесь мы сортируем по пилоту
    int pilot = part(vec, sortIndex, left, right);
    // после чего мы сортируем вокруг текущего пилота
    quickSorter(vec, sortIndex, left, pilot - 1);
    quickSorter(vec, sortIndex, pilot + 1, right);
}
