#include <algorithm>
#include <iostream>
#include <list>
#include <string>

void task2(){
    std::list<std::string> tasklist;

    tasklist.push_back("write backend");
    tasklist.push_front("write frontend");
    tasklist.push_front("deploy");
    tasklist.push_front("deploy");

    tasklist.sort();
    tasklist.unique();

    for (auto x : tasklist){
        std::cout << x << '\n';
    }
}
