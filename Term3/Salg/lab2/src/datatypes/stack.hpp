#include <stdexcept>

template<typename T>
class stack {
private:
    T* array;
    int curr_end = 0;
    int size;
public:
    stack(int sz = 10) : size(sz), curr_end(0) {
        if (sz<=0) std::runtime_error("creating zero size stack");
        array = new T[size];
    }

    stack(const stack&) = delete;
    stack& operator=(const stack&) = delete;

    ~stack() {
        delete[] array;
    }

    void push(T smth) {
        if (curr_end < size) {
            array[curr_end] = smth;
            curr_end++;
        } else {
            throw std::runtime_error("uve told that array should be smaller xD");
        }
    }

    T pop(){
        if (curr_end == 0) throw std::runtime_error("stack is empty");
        //если конец элементов назначен на 0, то значит ничего там нет
        curr_end--;
        T smth = array[curr_end];
        return smth;
    }

    T top() const {
        if (curr_end == 0) throw std::runtime_error("stack is empty");
        return array[curr_end - 1];
    }

    bool empty(){
        return curr_end == 0;
    }
    bool full(){
        return curr_end == size;
    }
    int count(){
        return curr_end;
    }
    int capacity(){ 
        return size; 
    }
};
