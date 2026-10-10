#include <stdexcept>

template<typename T>
class deque {
private:
    T* array;
    int front = 0; //индекс для следующей вставки, unlike queue.hpp, где это индекс элема
    int back = 0;
    bool isntEmpty = false;
    int size;

public:
    deque(int sz = 10) : size(sz), front(0), back(0), isntEmpty(false){
        if (sz <= 0) throw std::runtime_error("creating zero size deque");
        array = new T[size];
    }

    deque(const deque&) = delete;
    deque& operator=(const deque&) = delete;

    ~deque(){
        delete[] array;
    }

    void push_front(T smth){
        if (front == back && isntEmpty)
            throw std::runtime_error("deque is full");

        front = (front - 1 + size) % size;
        array[front] = smth;
        if (!isntEmpty){
            isntEmpty = true;
        }
    }

    void push_back(T smth){
        if (front == back && isntEmpty)
            throw std::runtime_error("deque is full");

        array[back] = smth;
        back = (back + 1) % size;
        if (!isntEmpty){
            isntEmpty = true;
        }
    }

    T pop_front(){
        if (!isntEmpty) throw std::runtime_error("deque is empty");
        T smth = array[front];
        front = (front + 1) % size;
        if (front == back) isntEmpty = false;
        return smth;
    }

    T pop_back(){
        if (!isntEmpty) 
            throw std::runtime_error("deque is empty");

        back = (back - 1 + size) % size;
        T smth = array[back];
        if (front == back) isntEmpty = false;
        return smth;
    }

    bool empty(){
        return !isntEmpty;
    }
    int count(){
        if (!isntEmpty) return 0;
        return (back - front + size) % size;
    }
};
