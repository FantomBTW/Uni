#include <fstream>
#include <vector>
#include <string>

std::ifstream csv_choise();
std::vector<std::string> read_header(std::ifstream& ourcsv);
std::vector<std::vector<std::string>> read_all_rows(std::ifstream& ourcsv);
