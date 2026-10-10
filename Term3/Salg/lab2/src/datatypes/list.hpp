#include <stdexcept>

template<typename T>
class list {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr){}
    };

    Node* head = nullptr;
    Node* tail = nullptr;
    int count = 0;

public:
    list() : head(nullptr), tail(nullptr), count(0){}

    list(const list&) = delete;
    list& operator=(const list&) = delete;

    ~list(){
        Node* current = head;
        while (current != nullptr){
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void push_front(T smth){
        Node* newNode = new Node(smth);
        if (head == nullptr){
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        count++;
    }

    void push_back(T smth){
        Node* newNode = new Node(smth);
        if (tail == nullptr){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    T pop_front(){
        if (head == nullptr) 
            throw std::runtime_error("list is empty");

        Node* temp = head;
        T val = temp->data;
        head = head->next;
        if (head == nullptr)
            tail = nullptr;

        delete temp;
        count--;
        return val;
    }

    T pop_back(){
        if (tail == nullptr) 
            throw std::runtime_error("list is empty");

        if (head == tail){
            T val = head->data;
            delete head;
            head = tail = nullptr;
            count--;
            return val;
        }
        Node* current = head;
        while (current->next != tail)
            current = current->next;

        T val = tail->data;
        delete tail;
        tail = current;
        tail->next = nullptr;
        count--;
        return val;
    }

    T front(){
        if (head == nullptr)
            throw std::runtime_error("list is empty");
        return head->data;
    }

    T back(){
        if (tail == nullptr)
            throw std::runtime_error("list is empty");
        return tail->data;
    }
};
