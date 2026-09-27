#pragma once

#include <vector>
#include "../csv/csv.hpp"

void quickSort(
        std::vector<Row>& vec,
        int sortIndex
    );

int part(
        std::vector<Row>& vec,
        int sortIndex,
        int left,
        int right,
        bool isNum
    );

void quickSorter(
        std::vector<Row>& vec,
        int sortIndex,
        int left,
        int right,
        bool isNum
    );
