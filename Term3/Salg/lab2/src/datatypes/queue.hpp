#include <stdexcept>
template<typename T>
class queue{
private:
    T* array;
    int put = 0;
    int get = 0;
    bool isFull = false;
    int size;
public:
    queue(int sz = 10) : size(sz), get(0), put(0){
        if (sz <= 0) throw std::runtime_error("creating zero size queue");
        array = new T[size];
    }

    queue(const queue&) = delete;
    queue& operator=(const queue&) = delete;

    ~queue() {
        delete[] array;
    }

    void push(T smth){
        if ( isFull )
            throw std::runtime_error("we can't add anymore");

        array[put] = smth;
        put = (put+1)%size;
        if (put == get)
            isFull = true;
    }

    T pop(){
        if(get == put && !isFull)
            throw std::runtime_error("queue is empty");
        T smth = array[get];
        get = (get+1)%size;
        isFull = false; //anyway after popping

        return smth;
    }

};
