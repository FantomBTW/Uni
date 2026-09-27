#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "tui/menu.hpp"
#include "csv/csv.hpp"
#include "sort/basesorts.hpp"

int main() {
    std::ifstream file = csv_choise();
    std::vector<std::string> headers = read_header(file);
    
    int colIndex = colChoise(headers);
    int sortMethod = sortChoise();
    
    std::vector<Row> rows = read_all_rows(file);
    
    dispatchSort(rows, colIndex, sortMethod);

    for (int i = 0; i < rows.size(); i++) {
        std::cout << rows[i].cells[1] << " | " << rows[i].cells[colIndex] << std::endl;
    }

    return 0;
}
