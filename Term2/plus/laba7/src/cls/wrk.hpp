#pragma once
template <typename T>
class worker {
private:
    T id;
    int prod; // productivity
public:
    worker(T id, int prod): id(id), prod(prod) {};

    T getId(){
        return id;
    }

    int getprod(){
        return prod;
    }

    bool operator<(const worker& anotherworker) const{
        return prod < anotherworker.prod;
    }

    int operator+(const worker& anotherworker) const{
        return prod+anotherworker.prod;
    }

    bool operator==(const worker& anotherworker) const{
        return id == anotherworker.id;
    }

    bool operator==(const T& anotherworker) const{
        return id == anotherworker;
    }
};
