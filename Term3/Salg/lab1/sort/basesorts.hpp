#pragma once

#include <vector>
#include "../csv/csv.hpp"

void swap(Row& a, Row& b);
void insertionSort(std::vector<Row>& vec, int sortIndex);
void selectionSort(std::vector<Row>& vec, int sortIndex);
void bubbleSort(std::vector<Row>& vec, int sortIndex);
