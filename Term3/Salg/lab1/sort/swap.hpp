#pragma once
#include "../csv/csv.hpp"
void swap(Row& a, Row& b);

//сравнение двух ячеек столбца sortIndex:
//  isNum == true  -> числовое сравнение numeric
//  isNum == false -> лексикографическое сравнение cells
//возвращает <0, если a меньше b; 0 если равны; >0 если a больше b
int cmp(const Row& a, const Row& b, int sortIndex, bool isNum);
