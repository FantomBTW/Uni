#pragma once

#include <vector>
#include "../csv/csv.hpp"

void heaps(
        std::vector<Row>& vec, //vec
        int n, //curren arr max
        int i, //current
        int sortIndex
    );

void heapSort(std::vector<Row>& vec, int sortIndex);
