#include <iostream>
#include <vector>
#include <string>
#include "class.hpp"


int main() {
    std::cout << "A:" << std::endl;
    Person p("Ivan", 25);
    p.displayInfo();

    std::cout << "\nB:" << std::endl;
    Student s("Anna", 20, 12345);
    s.displayInfo();

    std::cout << "\nC:" << std::endl;
    std::vector<Shape*> shapes;
    shapes.push_back(new Rectangle(5, 4));
    shapes.push_back(new Circle(3));

    for (Shape* s : shapes) {
        std::cout << "Area: " << s->calculateArea() << std::endl;
    }

    std::cout << "\nD:" << std::endl;
    Account acc(100.0);
    acc.deposit(50.0);
    acc.withdraw(30.0);
    std::cout << "Final balance: " << acc.getBalance() << std::endl;

    for (Shape* s : shapes) delete s;

    return 0;
}
