#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "tui/menu.hpp"
#include "csv/csv.hpp"

int main() {
    std::ifstream file = csv_choise();
    std::vector<std::string> headers = read_header(file);
    
    int colIndex = colChoise(headers);
    int sortMethod = sortChoise();
    
    std::vector<std::vector<std::string>> rows = read_all_rows(file);
    
    std::cout << "Headers: " << headers.size() << " columns\n";
    std::cout << "Rows: " << rows.size() << "\n";
    std::cout << "Sorted by column " << colIndex << " (" << headers[colIndex] << "), method " << sortMethod << "\n";
    
    return 0;
}
