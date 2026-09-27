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
        int right
    );

void quickSorter(
        std::vector<Row>& vec,
        int sortIndex,
        int left,
        int right
    );
