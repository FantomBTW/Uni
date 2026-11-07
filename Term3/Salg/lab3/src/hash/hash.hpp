#include <stdexcept>

template <typename T>
struct Node {
    T data;
    Node* next;
};


template <typename T>
class table {
private:
    int size;
    Node<T> datarr[];
public:
    table(int size) : size(size) {
        if (size<=1) {
            throw std::runtime_error("creating useless or impossible dataset");
        }
        datarr = new Node<T>[size];
    }

    table(const table&) = delete;
    table& operator=(const table&) = delete;

    ~table(){
        delete[] datarr();
    }
};
