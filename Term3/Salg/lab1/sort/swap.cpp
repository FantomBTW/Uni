#include "swap.hpp"
void swap(Row& a, Row& b) {
    Row temp = a;
    a = b;
    b = temp;
}
