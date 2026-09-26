#pragma once

#include <vector>
#include "../csv/csv.hpp"

void mergeSort(
        std::vector<Row>& vec,
        int sortIndex
);

void merge(
        std::vector<Row>& vec,
        int sortIndex,
        int left,
        int mid,
        int right
);

void mergerNSorter(
        std::vector<Row> &vec,
        int left, int right,
        
        int sortIndex
);
