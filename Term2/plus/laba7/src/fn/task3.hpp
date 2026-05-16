#include <iostream>
#include <set>
#include <string>

void task3(){
    std::set<std::string> setlist;

    setlist.insert("vika");
    setlist.insert("vasya");
    setlist.insert("vika");
    setlist.insert("vova");

    for (const auto& name : setlist){
        std::cout << name << '\n';
    }
    std::cout << std::endl;

    std::cout << "vova found status: " << (setlist.find("vova") == setlist.end());

    std::cout << "vova found status: " << (setlist.find("vlad") == setlist.end());
}
