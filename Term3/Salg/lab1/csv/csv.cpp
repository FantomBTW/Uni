#pragma once

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

std::ifstream csv_choise(){
    std::ifstream file("/home/fantom/git/Uni/Term3/Salg/lab1/csv/spotify.csv");
    if (!file.is_open()) throw std::runtime_error(
            "Файла не существует, или нет прав \n\
            ну или космический ветер подул, проверь на опечатки"
        );
    return file;
}

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

std::vector<std::vector<std::string>> read_all_rows(std::ifstream& ourcsv){
    std::vector<std::vector<std::string>> rows;
    std::string line;
    
    while (std::getline(ourcsv, line)) {
        std::vector<std::string> row;
        std::istringstream ss(line);
        std::string cell;
        
        while (std::getline(ss, cell, ',')) {
            row.push_back(cell);
        }
        
        if (!row.empty()) {
            rows.push_back(row);
        }
    }
    
    return rows;
}
