#include <iostream>
#include "vec/vec.hpp"

int main(){
    int choice;

    std::cout << "1 - vec" << '\n';
    std::cout << "0 - exit" << std::endl;

    std::cin >> choice;

    switch (choice) {
        case 0:
            break;
        case 1:
            int n, max;
            std::cout << "Enter n: ";
            std::cin >> n;
            std::cout << "Enter max: ";
            std::cin >> max;
            vecDemonstation(n, max);
            break;
    }

    return 0;
}
