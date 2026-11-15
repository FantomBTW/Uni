#include <cstdint>
#include <cstring>
#include <optional>
#include <stdexcept>

struct Node {
    char* key;
    int data;
    Node* next;
};


class table {
private:
    std::uint32_t size;
    std::uint32_t count = 0;
    Node* datarr;

    std::uint32_t hasher(const char* key) const;

    std::uint32_t findIndex(const char* key) const{
        return (hasher(key))%size;
    }

public:
    table(std::uint32_t size) : size(size) {
        if (size<=1) {
            throw std::runtime_error("creating useless or impossible dataset");
        }
        datarr = new Node[size]();
    }

    table(const table&) = delete;
    table& operator=(const table&) = delete;


    ~table() {
        for (std::uint32_t i = 0; i < size; ++i) {
            Node* cur = datarr[i].next;
            while (cur) {
                Node* next = cur->next;
                delete[] cur->key;
                delete cur;
                cur = next;
            }
        }
        delete[] datarr;
    }


    float calcfactor() {
        return static_cast<float>(count) / static_cast<float>(size);
    }


    void write(const char* key, const int data){
        if (key == nullptr) return;

        std::uint32_t index = findIndex(key);
        Node* currentNode = &datarr[index];

        while (currentNode->next != nullptr) {
            if (strcmp(currentNode->next->key, key)==0)
            {
                currentNode->next->data = data;
                return;
            } //if they're ident = upd data

            currentNode = currentNode->next; //goto next Node
        }

        char* keyOfNewNode = new char[strlen(key) + 1];
        strcpy(keyOfNewNode, key);
        currentNode->next = new Node{keyOfNewNode, data, nullptr};

        ++count;

        if (calcfactor() >= 0.75) recreate();
    }

    std::optional<int> find(const char* key) const{
        if(key == nullptr) return std::nullopt;

        std::uint32_t index = findIndex(key);
        Node* currentNode = &datarr[index];
        
        while (currentNode != nullptr) { //til end of Nodes
            if (currentNode-> key != nullptr && strcmp(key, currentNode->key)==0) {
                return currentNode->data;
            } // if we found key, return data

            currentNode = currentNode->next; //move on to the next one
        }
        return std::nullopt;
    }

    void remove(const char* key){
        if (key == nullptr) return;

        std::uint32_t index = findIndex(key);

        Node* previous = &datarr[index];
        Node* currentNode = previous->next;

        while (currentNode != nullptr) {
            if (strcmp(currentNode->key, key)==0) {
                previous->next = currentNode->next;
                delete[] currentNode->key;
                delete currentNode;

                --count;

                return;
            }

            previous = currentNode;
            currentNode = currentNode->next;
        }

        return;
    }


    void recreate(){
        std::uint64_t newSize = static_cast<unsigned int>(size) * 2;
        //64 for checker to work

        if (newSize > UINT32_MAX) throw std::runtime_error("too much data, pls, upgrade ur pc, program and smth else");

        Node* newArr = new Node[newSize]();

        //relink existing nodes, keys and data are reused as-is
        for (std::uint32_t i = 0; i < size; ++i) {
            Node* current = datarr[i].next;

            while (current != nullptr) {
                Node* next = current->next;
                std::uint32_t newIndex = hasher(current->key) % newSize;
                current->next = newArr[newIndex].next;
                newArr[newIndex].next = current;
                current = next;
            }

        }

        delete[] datarr;
        datarr = newArr;
        size = static_cast<std::uint32_t>(newSize);
    }

    float collisionPercentage() const{
        if (count ==0) return 0;

        std::uint32_t fullHeads = 0; //cnt of heads that have smth in it
        for (std::uint32_t i = 0; i < size; ++i) 
            if (datarr[i].next!=nullptr) 
                ++fullHeads;

        return static_cast<float>(count - fullHeads) / static_cast<float>(count);
    }
};
