#pragma once

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <limits>
#include "csv.hpp"

//TODO:реализовать выбор файла
std::ifstream csv_choise(){
    std::ifstream file("/home/fantom/git/Uni/Term3/Salg/lab1/csv/spotify.csv");
    if (!file.is_open()) throw std::runtime_error(
            "Файла не существует, или нет прав \n\
            ну или космический ветер подул, проверь на опечатки"
        );
    return file;
}

//читаем хедер для списка столбцов
std::vector<std::string> read_header(std::ifstream& ourcsv){
    std::string header;
    std::getline(ourcsv, header);

    std::vector<std::string> header_cols;
    std::istringstream ss(header);
    std::string someHeader;
    
    while (std::getline(ss, someHeader, ',')) {
        header_cols.push_back(someHeader);
    }
    
    return header_cols;
}

//парсим всё в Row формат для дальнейших сортировок
//иначе я не придумал, как оно должно быть реализовано
std::vector<Row> read_all_rows(std::ifstream& ourcsv){
    std::vector<Row> rows;
    std::string line;
    
    //берём по одной линии файла
    while (std::getline(ourcsv, line)) {
        Row row;
        std::istringstream ss(line);
        std::string cell;
        
        //парсим её в набор строк для вывода и набор decimal для сортировок
        while (std::getline(ss, cell, ',')) {
            row.cells.push_back(cell);
            try {
                row.numeric.push_back(std::stod(cell));
            } catch (...) {
                row.numeric.push_back(std::numeric_limits<double>::quiet_NaN());
            }
        }
        
        if (!row.cells.empty()) {
            rows.push_back(row);
        }
    }
    
    return rows;
}
