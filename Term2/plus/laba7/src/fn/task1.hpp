#include <algorithm>
#include <iostream>
#include <vector>
#include "../cls/wrk.hpp"

void task1(){
    std::vector<worker<std::string>> department;

    department.push_back(worker<std::string> ("vasya", 5));
    department.push_back(worker<std::string> ("vika", 10));
    department.push_back(worker<std::string> ("voldemar", 1));

    std::sort(department.begin(), department.end());

    std::cout << "worker of the month?" << std::endl;
    std::reverse(department.begin(), department.end());
    for (auto x : department){
        std::cout << x.getId() << " has productivity lvl:"<< x.getprod() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "what is vika productivity?" << std::endl;
    
    auto i = std::find(department.begin(), department.end(), std::string("vika"));
    std::cout << "she has productivity lvl:" << i->getprod() << std::endl;
}
