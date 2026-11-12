#include <stdexcept>

struct Node {
    char* key;
    int data;
    Node* next;
};


class table {
private:
    int size;
    Node* datarr;
    int usedcells = 0;

    int hasher();
public:
    table(int size) : size(size) {
        if (size<=1) {
            throw std::runtime_error("creating useless or impossible dataset");
        }
        datarr = new Node[size];
    }

    table(const table&) = delete;
    table& operator=(const table&) = delete;

    ~table(){
        delete[] datarr;
    }
};
