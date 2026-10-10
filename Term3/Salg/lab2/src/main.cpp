#include <iostream>
#include "datatypes/stack.hpp"
#include "datatypes/queue.hpp"

int main(){
    int ourSize = 10;

    char *smth = new char();

    queue<char> myQueue(ourSize);
    for (int i=0; i < ourSize; i++){
        std::cin >> *smth;
        myQueue.push(*smth);
    };
    for (int i=0; i < ourSize; i++){
        std::cout << myQueue.pop() << std::endl;
    };

    //stack<char> ourStack(ourSize);
    //char smth;
    //for (int i=0; i < ourSize; i++){
        //std::cin >> smth;
        //ourStack.push(smth);
    //}

    //for (int i=0; i < ourSize; i++){
        //std::cout << ourStack.pop();
    //}
}
