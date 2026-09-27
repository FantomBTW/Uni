#include "swap.hpp"
void swap(Row& a, Row& b) {
    Row temp = a;
    a = b;
    b = temp;
}

int cmp(const Row& a, const Row& b, int sortIndex, bool isNum) {
    if (isNum) {
        double lhs = a.numeric[sortIndex];
        double rhs = b.numeric[sortIndex];
        if (lhs < rhs) return -1;
        if (lhs > rhs) return 1;
        return 0;
    }
    //лексикографическое сравнение строк
    int res = a.cells[sortIndex].compare(b.cells[sortIndex]);
    if (res < 0) return -1;
    if (res > 0) return 1;
    return 0;
}
