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
    unsigned short int size;
    Node* datarr;
    //int usedcells = 0;

    std::uint32_t hasher(const char* key) const;

    unsigned short int findIndex(const char* key) const{
        uint32_t hash = hasher(key);
        unsigned short int index = hash%size;
        return index;
    }

public:
    table(unsigned short int size) : size(size) {
        if (size<=1) {
            throw std::runtime_error("creating useless or impossible dataset");
        }
        datarr = new Node[size]();
    }

    table(const table&) = delete;
    table& operator=(const table&) = delete;

    ~table(){
        delete[] datarr;
    }

    void write(const char* key, const int data){
        if (key == nullptr) return;

        unsigned short int index = findIndex(key);
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
    }

    std::optional<int> find(const char* key) const{
        unsigned short int index = findIndex(key);
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

        unsigned short int index = findIndex(key);

        Node* previous = &datarr[index];       //sentinel: never deleted, keeps the bucket valid
        Node* currentNode = previous->next;

        while (currentNode != nullptr) {
            if (strcmp(currentNode->key, key)==0) {
                previous->next = currentNode->next;
                delete[] currentNode->key;
                delete currentNode;
                return;
            }

            previous = currentNode;
            currentNode = currentNode->next;
        }

        return;
    }
};
