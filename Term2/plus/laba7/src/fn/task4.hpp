#include <iostream>
#include <stack>
#include <string>

void task4(){
    std::stack<std::string> podpisOfJournal; // обычно последним подписывают журнал тому, кто первый подошёл

    podpisOfJournal.push("Vanya 517");
    podpisOfJournal.push("Serzhiq 515");
    podpisOfJournal.push("Vanya 511");

    while (!podpisOfJournal.empty()){
        std::cout << "journal has podpised for: " << podpisOfJournal.top();
        podpisOfJournal.pop();
        std::cout << std::endl;
    }
}
