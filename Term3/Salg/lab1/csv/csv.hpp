#pragma once

#include <fstream>
#include <vector>
#include <string>

struct Row {
    std::vector<std::string> cells;
    std::vector<double> numeric;
};

std::ifstream csv_choise();
std::vector<std::string> read_header(std::ifstream& ourcsv);
std::vector<Row> read_all_rows(std::ifstream& ourcsv);
