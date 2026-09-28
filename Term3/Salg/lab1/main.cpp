#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>

#include "tui/menu.hpp"
#include "csv/csv.hpp"
#include "sort/basesorts.hpp"

int main() {
    std::ifstream file = csv_choise();
    std::vector<std::string> headers = read_header(file);
    
    int colIndex = colChoise(headers);
    int sortMethod = sortChoise();
    
    std::vector<Row> rows = read_all_rows(file);
    
    auto start = std::chrono::high_resolution_clock::now();
    dispatchSort(rows, colIndex, sortMethod);
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    for (int i = 0; i < rows.size(); i++) {
        std::cout << rows[i].cells[1] << " | " << rows[i].cells[colIndex] << std::endl;
    }

    std::cout << "\nTime: " << duration.count() << " microseconds" << std::endl;

    return 0;
}
