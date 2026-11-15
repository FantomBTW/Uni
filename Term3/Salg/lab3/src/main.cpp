#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

#include "hash/hash.hpp"

int main() {
    table t(8);
    int choice = -1;

    do {
        std::cout << "\n1. add \n2. delete\n3. find\n4. loadfactor\n5. collisionPercentage\n0. exit\n";

        if (!(std::cin >> choice)) {
            if (std::cin.eof()) break;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Введите число от 0 до 4\n";
            choice = -1;   // при ошибке ввода cin записывает 0, не выходим
            continue;
        }

        std::string key;
        int value;

        switch (choice) {
        case 1:
            std::cout << "Ключ: ";
            std::cin >> key;
            std::cout << "Значение: ";
            if (!(std::cin >> value)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Некорректное число\n";
                break;
            }
            t.write(key.c_str(), value);
            std::cout << "Добавлено\n";
            break;

        case 2:
            std::cout << "Ключ: ";
            std::cin >> key;
            if (t.find(key.c_str())) {
                t.remove(key.c_str());
                std::cout << "Удалено\n";
            } else {
                std::cout << "Ключ не найден\n";
            }
            break;

        case 3: {
            std::cout << "Ключ: ";
            std::cin >> key;
            auto res = t.find(key.c_str());
            if (res) std::cout << key << " = " << *res << "\n";
            else     std::cout << "Ключ не найден\n";
            break;
        }

        case 4:
            std::cout << "Коэффициент заполнения: " << t.calcfactor() << "\n";
            break;

        case 5:
            std::cout << "Коллизии: " << std::fixed << std::setprecision(1)
                << t.collisionPercentage() << " %\n";
            break;

        case 0:
            std::cout << "Выход\n";
            break;

        default:
            std::cout << "Нет такого пункта\n";
        }
    } while (choice != 0);

    return 0;
}
