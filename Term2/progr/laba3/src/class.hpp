#include <iostream>
#include <string>

class Person {
protected:
    std::string name;
    int age;

public:
    Person(std::string n, int a) : name(n), age(a) {}

    void setName(std::string n) { name = n; }
    std::string getName() { return name; }

    virtual void displayInfo() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
    virtual ~Person() {}
};

class Student : public Person {
private:
    int studentId;

public:
    Student(std::string n, int a, int id) : Person(n, a), studentId(id) {}

    int getStudentId() { return studentId; }

    void displayInfo() override {
        std::cout << "Student: " << name << ", Age: " << age 
                  << ", ID: " << studentId << std::endl;
    }
};

class Shape {
public:
    virtual double calculateArea() = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double calculateArea() override { return width * height; }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double calculateArea() override { return 3.14 * radius * radius; }
};

class Account {
private:
    double balance;

public:
    Account(double initialBalance) : balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) balance += amount;
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }

    double getBalance() { return balance; }
};
