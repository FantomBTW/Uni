#pragma once

#include <vector>
#include "../csv/csv.hpp"
void insertionSort(std::vector<Row>& vec, int sortIndex);
void selectionSort(std::vector<Row>& vec, int sortIndex);
void bubbleSort(std::vector<Row>& vec, int sortIndex);

void dispatchSort(std::vector<Row>& vec, int sortIndex, int sortMethod);
